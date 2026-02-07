PORTNAME=	term-background
DISTVERSION=	1.0.3
CATEGORIES=	deskutils python shells
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Shell scripts and Python module to figure out terminal background
WWW=		https://github.com/rocky/shell-term-background

LICENSE=	GPLv3

#USE_GITHUB=	yes
#GH_ACCOUNT=	rocky
#GH_PROJECT=	shell-term-background
#GH_TAGNAME=	55a9cd227d6428d72f78a2411479eeade1300dff

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=0:sysutils/py-pkginfo@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	distutils

NO_ARCH=	yes
MAKE_ENV+=	PYTHON=${PYTHON_CMD}
PLIST_SUB=	VER=${DISTVERSION}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/term-background.*h ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
