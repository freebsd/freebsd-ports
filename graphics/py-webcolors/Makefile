# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webcolors
PORTVERSION=	1.4
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Library working with the sRGB color space as used in the HTML and CSS

LICENSE=	BSD3CLAUSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
PORTDOCS=	README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
