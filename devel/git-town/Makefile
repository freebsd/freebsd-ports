# $FreeBSD$

PORTNAME=	git-town
DISTVERSIONPREFIX=	v
DISTVERSION=	7.3.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Git extension for generic, high-level git workflow support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	Originate
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install-DOCS-on:
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
