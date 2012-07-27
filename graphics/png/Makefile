# New ports collection makefile for:    PNG images library
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.5.12
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/lib${PORTNAME}15/${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Library for manipulating PNG images

MAKE_JOBS_SAFE=	yes

USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DPNG_MAN_DIR:STRING=man
SOSUFFIX=	.${PORTVERSION:E}

MAN3=		libpng.3 libpngpf.3
MAN5=		png.5

OPTIONS=	APNG "Animated PNG support" On

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
BROKEN=		Please remove WITH_DEBUG for this port
.endif

.if !defined(WITHOUT_APNG) || make(makesum) || defined(FETCH_ALL)
MASTER_SITES+=	SF/apng/libpng/libpng15/:apng
DISTFILES+=	${DISTNAME}-apng.patch.gz:apng
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif
.if !defined(WITHOUT_APNG)
EXTRA_PATCHES=	${WRKSRC}/${DISTNAME}-apng.patch
.endif

post-extract:
.if !defined(WITHOUT_APNG)
	@${LN} -sf ${WRKSRC} ${WRKSRC}/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}-apng.patch.gz ${WRKSRC}/
	${GZIP_CMD} -d ${WRKSRC}/${DISTNAME}-apng.patch.gz
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|RELEASE}.0|RELEASE}|' \
		-e 's|LIBDIR}/pkgconfig|LIBDIR}data/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

post-build:
	@(cd ${BUILD_WRKSRC}; if ! ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} test; then \
        if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
            ${ECHO_MSG} "===> Compilation failed unexpectedly."; \
            (${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
            fi; \
        ${FALSE}; \
        fi)

pre-su-install:
	@${MKDIR} ${PREFIX}/include/libpng
	@${MKDIR} ${PREFIX}/libdata/pkgconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/pngdebug.h ${WRKSRC}/pnginfo.h \
		${WRKSRC}/pngpriv.h ${WRKSRC}/pngstruct.h \
		${PREFIX}/include/libpng15/
	-${RMDIR} ${PREFIX}/include/libpng
	${RM} ${PREFIX}/libdata/pkgconfig/libpng.pc
	${LN} -sf libpng15.pc ${PREFIX}/libdata/pkgconfig/libpng.pc
	${RM} ${PREFIX}/lib/libpng15.so.15
	${MV} ${PREFIX}/lib/libpng15.so.15${SOSUFFIX} ${PREFIX}/lib/libpng15.so.15

.include <bsd.port.post.mk>
