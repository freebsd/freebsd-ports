# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linux-adobesvg
DISTVERSION=	3.01x88
CATEGORIES=	graphics www linux
MASTER_SITES=	http://download.adobe.com/pub/adobe/magic/svgviewer/linux/3.x/${DISTVERSION}/en/
DISTNAME=	adobesvg-${DISTVERSION}-linux-i386

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Adobe SVG browser plugin (Linux version)

ONLY_FOR_ARCHS=	i386 amd64
USES=		linux
USE_LINUX=	xorglibs
USE_LDCONFIG=	yes

RESTRICTED=	Redistribution prohibited
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/adobesvg-${PORTVERSION:S/.x88//}

LIBDIR=		${PREFIX}/lib/linux-adobesvg
SHLIBS=		ACE AGM BIB CoolType NPSVG3 SVGCore
SHLIB_FILES=	${SHLIBS:S|^|lib|:S|$|.so|}

PLIST_FILES=	${SHLIB_FILES:S|^|lib/linux-adobesvg/|}
PORTDOCS=	LICENSE.txt ReadMe.html SVGHelp.html

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LIBDIR}
	${INSTALL_PROGRAM} ${SHLIB_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${LIBDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
