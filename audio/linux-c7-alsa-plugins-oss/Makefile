PORTNAME=	alsa-plugins
PORTVERSION=	1.1.6
DISTVERSIONSUFFIX=	-1.el7
PORTREVISION=	4
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
WWW=		https://www.alsa-project.org/

LICENSE=	LGPL21+

USES=		autoreconf:build gmake libtool:build linux:c7 pkgconfig
USE_LDCONFIG=	yes
USE_LINUX=	alsalib:build,run alsa-lib-devel:build base:build devtools:build
USE_LINUX_PREFIX=yes

RPM_PATCHES=	alsa-plugins-1.1.6-post.patch \
		alsa-plugins-1.1.6-speexdsp.patch
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

CONFLICTS=	linux-c6-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
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

do-patch:
	@${REINPLACE_CMD} 's/mkdir -p/$$(MKDIR_P)/' \
		${WRKDIR}/alsa-plugins-1.1.6-post.patch
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
	@(cd ${WRKSRC32} && ${AUTORECONF} -f -i && ${SETENVI} ${WRK_ENV} \
		PATH=${LINUXBASE}/usr/bin ./configure CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS:N-march=*} ${COMPAT32_CFLAGS_${ARCH}}" \
		LDFLAGS="${LDFLAGS}" MAKE="${MAKE_CMD}" \
		MKDIR_P="${MKDIR}" PKG_CONFIG="${LOCALBASE}/bin/pkgconf" \
		PKG_CONFIG_PATH=${LINUXBASE}/usr/lib/pkgconfig \
		${CONFIG_ARGS})
.endif
	@(cd ${WRKSRC} && ${AUTORECONF} -f -i && ${SETENVI} ${WRK_ENV} \
		PATH=${LINUXBASE}/usr/bin ./configure CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS:N-march=*}" LDFLAGS="${LDFLAGS}" \
		MAKE="${MAKE_CMD}" MKDIR_P="${MKDIR}" \
		PKG_CONFIG="${LOCALBASE}/bin/pkgconf" \
		PKG_CONFIG_PATH=${LINUXBASE}${LIBDIR_${ARCH}}/pkgconfig \
		--libdir ${LIBDIR_${ARCH}} ${CONFIG_ARGS})

do-build:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@(cd ${WRKSRC32} && ${SETENVI} ${WRK_ENV} PATH=${LINUXBASE}/usr/bin \
		${MAKE_CMD})
.endif
	@(cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} PATH=${LINUXBASE}/usr/bin \
		${MAKE_CMD})

do-install:
.if !empty(COMPAT32_CFLAGS_${ARCH})
	@(cd ${WRKSRC32} && ${SETENVI} ${WRK_ENV} PATH=${LINUXBASE}/usr/bin \
		${MAKE_CMD} install-strip DESTDIR=${STAGEDIR}${LINUXBASE})
	${RM} -r ${STAGEDIR}${LINUXBASE}/usr/lib/alsa-lib/*.la
.endif
	@(cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} PATH=${LINUXBASE}/usr/bin \
		${MAKE_CMD} install-strip DESTDIR=${STAGEDIR}${LINUXBASE})
	${RM} -r ${STAGEDIR}${LINUXBASE}${LIBDIR_${ARCH}}/alsa-lib/*.la
	${LN} -sf ../../../usr/share/alsa/alsa.conf.d/50-oss.conf \
		${STAGEDIR}${LINUXBASE}/etc/alsa/conf.d

.include <bsd.port.mk>
