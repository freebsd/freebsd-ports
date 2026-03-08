PORTNAME=	ghpr
DISTVERSIONPREFIX=	v
DISTVERSION=	2
CATEGORIES=	devel python

MAINTAINER=	imp@FreeBSD.org
COMMENT=	GitHub Pull Request landing tool for FreeBSD
WWW=		https://github.com/bsdimp/ghpr

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	gh:devel/gh \
		git:devel/git

USES=		python:3.8+ shebangfix
SHEBANG_GLOB=	*.py
USE_PYTHON=	py3kplist

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ghpr

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ghpr.py ${STAGEDIR}${PREFIX}/bin/ghpr

.include <bsd.port.mk>
