# New ports collection makefile for:	generic-haskell
# Date created:				05 July 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	generic-haskell
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.cs.uu.nl/research/projects/generic-haskell/compiler/beryl/
DISTNAME=	gh-${PORTVERSION}-source

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	The Generic Haskell compiler

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

USE_SIZE=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	gh

WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}
GHLIBDIR=	${PREFIX}/lib/generic-haskell

post-patch:
	@${REINPLACE_CMD} -e 's|@prefix@|${PREFIX}|' ${WRKSRC}/src/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/gh ${PREFIX}/bin
	@${MKDIR} ${GHLIBDIR}
	@${CP} -R ${WRKSRC}/lib/*.gh[is] ${GHLIBDIR}
	@${CP} -R ${WRKSRC}/lib/*.h[is] ${GHLIBDIR}
	@${MKDIR} ${GHLIBDIR}/Exts
	@${CP} -R ${WRKSRC}/lib/Exts/*.gh[is] ${GHLIBDIR}/Exts
	@${MKDIR} ${GHLIBDIR}/Std
	@${CP} -R ${WRKSRC}/lib/Std/*.gh[is] ${GHLIBDIR}/Std
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
