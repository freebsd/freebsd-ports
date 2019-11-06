# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	cobf
PORTVERSION=	1.06
CATEGORIES=	devel
MASTER_SITES=	http://home.arcor.de/bernhard.baier/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ code obfuscator

BROKEN=		unfetchable

USES=		zip

BUILD_WRKSRC=	${WRKSRC}/src/cpp
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/cobf
PORTDOCS=	COPYING README cobf.pdf

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cpp/cobf ${STAGEDIR}${PREFIX}/bin/cobf
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/copyright.txt ${STAGEDIR}${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/doc/cobf.pdf ${STAGEDIR}${DOCSDIR}/cobf.pdf

.include <bsd.port.mk>
