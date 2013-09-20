# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webcolors
PORTVERSION=	1.4
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Library working with the sRGB color space as used in the HTML and CSS

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
PORTDOCS=	README

.if !defined(NOPORTDOCS)
NO_STAGE=	yes
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
