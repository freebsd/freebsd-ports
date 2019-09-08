# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	alsa-plugins
PORTVERSION=	1.1.6
DISTVERSIONSUFFIX=	-1.el7
PORTREVISION=	2
CATEGORIES=	audio linux
MASTER_SITES=	CENTOS_LINUX
MASTER_SITE_SUBDIR=	centos/${LINUX_DIST_VER}/os/Source/SPackages/ \
			centos/${LINUX_DIST_VER}/updates/Source/SPackages/
PKGNAMEPREFIX=	linux-c7-
PKGNAMESUFFIX=	-oss
EXTRACT_SUFX=	.src.rpm
DIST_SUBDIR=	centos

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OSS plugin for ALSA (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL21+

USES=		autoreconf:build linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	alsalib:build,run alsa-lib-devel:build devtools:build \
		make:build
USE_LINUX_PREFIX=yes

RPM_PATCHES=	alsa-plugins-1.1.6-post.patch \
		alsa-plugins-1.1.6-speexdsp.patch
CONFIG_ARGS=	--disable-static --disable-mix --disable-usbstream \
		--disable-arcamav --disable-jack --disable-pulseaudio \
		--disable-samplerate --disable-libav --disable-a52 \
		--disable-lavrate --disable-speexdsp --with-speex=no
CFLAGS+=	-DFREEBSD_OSS -DFREEBSD_OSS_USE_IO_PTR -DFREEBSD_OSS_BUFSZ_P2
CFLAGS_amd64=	-nostdinc -isystem \
		${LINUXBASE}/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include \
		-isystem /usr/include
CFLAGS_i386=	-nostdinc -isystem \
		${LINUXBASE}/usr/lib/gcc/i686-redhat-linux/4.8.5/include \
		-isystem /usr/include
COMPAT32_CFLAGS_amd64=	-m32
LIBDIR_amd64=	/usr/lib64
LIBDIR_i386=	/usr/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC32=	${WRKDIR}/32/${PORTNAME}-${PORTVERSION}

CONFLICTS=	linux-c6-${PORTNAME}${PKGNAMESUFFIX}-[0-9]*
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
PLIST=		${PKGDIR}/pkg-plist.${ARCH}

post-extract:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@${MKDIR} ${WRKDIR}/32
	@(cd ${WRKDIR}/32 && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		../${PORTNAME}-${PORTVERSION}.tar.bz2 ${EXTRACT_AFTER_ARGS})
.endif
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${PORTNAME}-${PORTVERSION}.tar.bz2 ${EXTRACT_AFTER_ARGS})

do-patch:
.for p in ${RPM_PATCHES}
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@${PATCH} -d ${WRKSRC32} --forward --quiet -E -p1 < ${WRKDIR}/${p}
.endif
	@${PATCH} -d ${WRKSRC} --forward --quiet -E -p1 < ${WRKDIR}/${p}
.endfor
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@${CAT} ${PATCHDIR}/patch-* | ${PATCH} -d ${WRKSRC32} --forward \
		--quiet -E -p0
.endif
	@${CAT} ${PATCHDIR}/patch-* | ${PATCH} -d ${WRKSRC} --forward \
		--quiet -E -p0

do-configure:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@(cd ${WRKSRC32} && ${AUTORECONF} -f -i && ${SETENV} \
		PKG_CONFIG_PATH=${LINUXBASE}/usr/lib/pkgconfig \
		${LINUXBASE}/bin/sh ./configure \
		CFLAGS="${CFLAGS} ${COMPAT32_CFLAGS_${ARCH}}" ${CONFIG_ARGS})
.endif
	@(cd ${WRKSRC} && ${AUTORECONF} -f -i && ${SETENV} \
		PKG_CONFIG_PATH=${LINUXBASE}${LIBDIR_${ARCH}}/pkgconfig \
		${LINUXBASE}/bin/sh ./configure --libdir ${LIBDIR_${ARCH}} \
		CFLAGS="${CFLAGS}" ${CONFIG_ARGS})

do-build:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@(cd ${WRKSRC32} && ${LINUXBASE}/usr/bin/make)
.endif
	@(cd ${WRKSRC} && ${LINUXBASE}/usr/bin/make)

do-install:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@(cd ${WRKSRC32} && ${LINUXBASE}/usr/bin/make install-strip \
		DESTDIR=${STAGEDIR}${LINUXBASE})
	${RM} -r ${STAGEDIR}${LINUXBASE}/usr/lib/alsa-lib/*.la
.endif
	@(cd ${WRKSRC} && ${LINUXBASE}/usr/bin/make install-strip \
		DESTDIR=${STAGEDIR}${LINUXBASE})
	${RM} -r ${STAGEDIR}${LINUXBASE}${LIBDIR_${ARCH}}/alsa-lib/*.la
	${RM} -r ${STAGEDIR}${LINUXBASE}/etc ${STAGEDIR}${LINUXBASE}/usr/share

.include <bsd.port.mk>
