PORTNAME=	alsa-plugins
PORTVERSION=	1.2.7.1
DISTVERSIONSUFFIX=	-1.el9
PORTREVISION=	3
CATEGORIES=	audio linux
MASTER_SITES=	ROCKY_LINUX
MASTER_SITE_SUBDIR=	${LINUX_DIST_VER}/BaseOS/source/tree/Packages/a/ \
			${LINUX_DIST_VER}/AppStream/source/tree/Packages/a/
PKGNAMEPREFIX=	linux-rl9-
PKGNAMESUFFIX=	-oss
EXTRACT_SUFX=	.src.rpm
DIST_SUBDIR=	rocky/a

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OSS plugin for ALSA (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.alsa-project.org/

LICENSE=	LGPL21+

USES=		autoreconf:build gmake libtool:build linux:rl9 pkgconfig
USE_LDCONFIG=	yes
USE_LINUX=	alsalib:build,run alsa-lib-devel:build base:build devtools:build libsigsegv:build,run
USE_LINUX_PREFIX=yes

CONFIG_ARGS=	--disable-static --disable-mix --disable-usbstream \
		--disable-arcamav --disable-jack --disable-pulseaudio \
		--disable-samplerate --disable-libav --disable-a52 \
		--disable-lavrate --disable-speexdsp --with-speex=no
CPPFLAGS+=	-DFREEBSD_OSS -DFREEBSD_OSS_USE_IO_PTR
CFLAGS+=	--sysroot=${LINUXBASE}
COMPAT32_CFLAGS_amd64=	-m32
LIBDIR_aarch64=	/usr/lib64
LIBDIR_amd64=	/usr/lib64
LIBDIR_i386=	/usr/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC32=	${WRKDIR}/32/${PORTNAME}-${PORTVERSION}

CONFLICTS=	linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
PLIST=		${PKGDIR}/pkg-plist.${ARCH}

.include <bsd.port.options.mk>

post-extract:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@${MKDIR} ${WRKDIR}/32
	@(cd ${WRKDIR}/32 && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		../${PORTNAME}-${PORTVERSION}.tar.bz2 ${EXTRACT_AFTER_ARGS})
.endif
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${PORTNAME}-${PORTVERSION}.tar.bz2 ${EXTRACT_AFTER_ARGS})

do-configure:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@(cd ${WRKSRC32} && ${AUTORECONF} -f -i && ${SETENV} \
		PATH=${LINUXBASE}/usr/bin ./configure CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS:N-march=*} ${COMPAT32_CFLAGS_${ARCH}}" \
		LDFLAGS="${LDFLAGS}" MAKE="${LOCALBASE}/bin/gmake" \
		MKDIR_P="${MKDIR}" PKG_CONFIG="${LOCALBASE}/bin/pkgconf" \
		PKG_CONFIG_PATH=${LINUXBASE}/usr/lib/pkgconfig \
		${CONFIG_ARGS})
.endif
	@(cd ${WRKSRC} && ${AUTORECONF} -f -i && ${SETENV} \
		PATH=${LINUXBASE}/usr/bin ./configure CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS:N-march=*}" LDFLAGS="${LDFLAGS}" \
		MAKE="${LOCALBASE}/bin/gmake" MKDIR_P="${MKDIR}" \
		PKG_CONFIG="${LOCALBASE}/bin/pkgconf" \
		PKG_CONFIG_PATH=${LINUXBASE}${LIBDIR_${ARCH}}/pkgconfig \
		--libdir ${LIBDIR_${ARCH}} ${CONFIG_ARGS})

do-build:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@(cd ${WRKSRC32} && ${SETENV} PATH=${LINUXBASE}/usr/bin \
		${LOCALBASE}/bin/gmake)
.endif
	@(cd ${WRKSRC} && ${SETENV} PATH=${LINUXBASE}/usr/bin \
		${LOCALBASE}/bin/gmake)

do-install:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@(cd ${WRKSRC32} && ${SETENV} PATH=${LINUXBASE}/usr/bin \
		${LOCALBASE}/bin/gmake install-strip \
		DESTDIR=${STAGEDIR}${LINUXBASE})
	${RM} -r ${STAGEDIR}${LINUXBASE}/usr/lib/alsa-lib/*.la
.endif
	@(cd ${WRKSRC} && ${SETENV} PATH=${LINUXBASE}/usr/bin \
		${LOCALBASE}/bin/gmake install-strip \
		DESTDIR=${STAGEDIR}${LINUXBASE})
	${RM} -r ${STAGEDIR}${LINUXBASE}${LIBDIR_${ARCH}}/alsa-lib/*.la
	${MKDIR} ${STAGEDIR}${LINUXBASE}/etc/alsa/conf.d
	${LN} -sf ../../../usr/share/alsa/alsa.conf.d/50-oss.conf \
		${STAGEDIR}${LINUXBASE}/etc/alsa/conf.d

## Pet poudriere's stage-qa
post-install:
.if defined(WRKDIRPREFIX) && !empty(WRKDIRPREFIX)
	${RM} -r ${LINUXBASE}${WRKDIRPREFIX}
.endif

.include <bsd.port.mk>
