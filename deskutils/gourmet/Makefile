# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gourmet
PORTVERSION=	0.17.4
PORTREVISION=	7
CATEGORIES=	deskutils gnome

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GNOME recipe manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:textproc/py-elib.intl@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poppler>=0:graphics/py-poppler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtf>=0:print/py-rtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:textproc/py-elib.intl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>0:www/py-beautifulsoup32@${PY_FLAVOR}

OPTIONS_DEFINE=		IPYTHON
IPYTHON_DESC=		Interactive shell support
IPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR}

USES=		gettext gnome python:-2.7
USE_GNOME=	intltool pygnome2 pygtk2
USE_PYTHON=	autoplist distutils
PLIST_FILES+=	man/man1/gourmet.1.gz
USE_GITHUB=	yes
GH_ACCOUNT=	thinkle

post-patch:
	@${REINPLACE_CMD} -e "s,'spellcheck',#'spellcheck',g" \
		${WRKSRC}/gourmet/plugin_loader.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/gourmet.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
