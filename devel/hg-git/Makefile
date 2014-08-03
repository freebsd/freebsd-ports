# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	hg-git
PORTVERSION=	0.6.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@posteo.eu
COMMENT=	Mercurial extension to pull from or push to a Git repository

LICENSE=	GPLv2

RUN_DEPENDS=	${PKGNAMEPREFIX}dulwich>=*:${PORTSDIR}/devel/dulwich \
		mercurial>=*:${PORTSDIR}/devel/mercurial \

PORTDOCS=	README.md

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
