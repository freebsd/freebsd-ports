PORTNAME=	mcomix
DISTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/MComix-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	shoesoft@gmx.net
COMMENT=	GTK3 comic book viewer
WWW=		https://sourceforge.net/projects/mcomix/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		desktop-file-utils gnome python
USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	RAR
OPTIONS_DEFAULT=RAR

RAR_DESC=	RAR (.cbr) comic book archives support
RAR_RUN_DEPENDS=${LOCALBASE}/lib/libunrar.so:archivers/libunrar

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} share ${STAGEDIR}${PREFIX})

.include <bsd.port.mk>
