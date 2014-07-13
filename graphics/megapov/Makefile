# Created by: maho@FreeBSD.org
# $FreeBSD$

PORTNAME=	megapov
PORTVERSION=	1.2.1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://megapov.inetart.net/packages/unix/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Unofficial extensions of POV-Ray

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray-meta
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff


WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
ALL_TARGET=	# empty
CONFIGURE_ARGS+=	COMPILED_BY="ports@FreeBSD.org"
LDFLAGS+= -L${LOCALBASE}/lib -L${LOCALBASE}/lib
CFLAGS+= -I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
CXXFLAGS+= -I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
CPPFLAGS+= -I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
LIB_DEPENDS+=	libvga.so:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
.if (${ARCH} == "i386")
CFLAGS+=	-mcpu=i686 -march=i686 -mfancy-math-387
CXXFLAGS+=	-mcpu=i686 -march=i686 -mfancy-math-387
.endif # i386
.endif

pre-build:
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

do-install:
	@(cd ${WRKSRC}/unix    ; ${MAKE_CMD} install)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKSRC}/doc -cf - . | \
		${TAR} -C ${DOCSDIR} -xf -
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC} -cf - include scenes  | \
		${TAR} -C ${EXAMPLESDIR} -xf -
	@${FIND} ${EXAMPLESDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.post.mk>
