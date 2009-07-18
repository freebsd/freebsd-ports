# New ports collection makefile for:    MegaPov
# Date created:         25 July 2003
# Whom:                 maho@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	megapov
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://megapov.inetart.net/packages/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Unofficial extensions of POV-Ray

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	# empty
CONFIGURE_ARGS+=	COMPILED_BY="ports@FreeBSD.org"
LDFLAGS+= -L${LOCALBASE}/lib -L${LOCALBASE}/lib
CFLAGS+= -I${LOCALBASE}/include
CXXFLAGS+= -I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
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
	@(cd ${WRKSRC}/unix    ; ${GMAKE} install)
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
