# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gourmet
PORTVERSION=	0.17.4
PORTREVISION=	4
CATEGORIES=	deskutils gnome

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GNOME recipe manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:textproc/py-elib.intl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}poppler>=0:graphics/py-poppler \
		${PYTHON_PKGNAMEPREFIX}rtf>=0:print/py-rtf \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:textproc/py-elib.intl \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>0:www/py-beautifulsoup32

OPTIONS_DEFINE=		IPYTHON
IPYTHON_DESC=		Interactive shell support
IPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython

USES=		gettext python:-2.7
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
