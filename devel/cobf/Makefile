# New ports collection makefile for:	cobf
# Date created:				14 May 2006
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	cobf
PORTVERSION=	1.06
CATEGORIES=	devel
MASTER_SITES=	http://home.arcor.de/bernhard.baier/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ code obfuscator

USE_ZIP=	yes
WRKSRC=		${WRKDIR}
PORTDOCS=	COPYING README cobf.pdf
PLIST_FILES=	bin/cobf

do-build:
	@${MAKE} -C ${WRKSRC}/src/cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cpp/cobf ${PREFIX}/bin/cobf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/copyright.txt ${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/doc/cobf.pdf ${DOCSDIR}/cobf.pdf
.endif

.include <bsd.port.mk>
