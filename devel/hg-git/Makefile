# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	hg-git
PORTVERSION=	0.8.6
CATEGORIES=	devel python
MASTER_SITES=	http://bitbucket.org/durin42/${PORTNAME}/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}

MAINTAINER=	marco.broeder@posteo.eu
COMMENT=	Mercurial extension to pull from or push to a Git repository

LICENSE=	GPLv2

RUN_DEPENDS=	${PKGNAMEPREFIX}dulwich>=*:devel/dulwich \
		mercurial>=*:devel/mercurial

PORTDOCS=	README.md

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/durin42-${PORTNAME}-1bd9d9a0201c
USES=		python:2.7
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
