# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	cobf
PORTVERSION=	1.06
CATEGORIES=	devel
MASTER_SITES=	http://home.arcor.de/bernhard.baier/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ code obfuscator

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}
PORTDOCS=	COPYING README cobf.pdf
PLIST_FILES=	bin/cobf
MAKEFILE=	makefile
BUILD_WRKSRC=	${WRKSRC}/src/cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cpp/cobf ${STAGEDIR}${PREFIX}/bin/cobf
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/copyright.txt ${STAGEDIR}${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/doc/cobf.pdf ${STAGEDIR}${DOCSDIR}/cobf.pdf

.include <bsd.port.mk>
