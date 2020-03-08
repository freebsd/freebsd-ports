# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	hg-git
DISTVERSION=	0.8.12
CATEGORIES=	devel python
MASTER_SITES=	http://bitbucket.org/durin42/${PORTNAME}/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	marco.broeder@posteo.eu
COMMENT=	Mercurial extension to pull from or push to a Git repository

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dulwich>=*:devel/dulwich@${PY_FLAVOR} \
		mercurial>=*:devel/mercurial

PORTDOCS=	README.md

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/durin42-${PORTNAME}-c651bb6fcf33
USES=		python:2.7
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
