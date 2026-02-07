PORTNAME=	rednotebook
DISTVERSIONPREFIX=v
DISTVERSION=	2.31
PORTREVISION=	4
CATEGORIES=	deskutils

MAINTAINER=	cth-freebsd@pm.me
COMMENT=	Personal desktop journaling application written in Python
WWW=		https://rednotebook.app

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk@40

USES=		gettext-tools:build gnome python
USE_GNOME=	gtk30 gtksourceview3
USE_GITHUB=	yes
GH_ACCOUNT=	jendrikseipp

NO_ARCH=	yes

OPTIONS_DEFINE=		ENCHANT NLS
OPTIONS_DEFAULT=	ENCHANT
OPTIONS_SUB=		yes
ENCHANT_DESC=		Use PyEnchant for spell checking
ENCHANT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=1.6:textproc/py-enchant
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

USE_PYTHON=	distutils

.include <bsd.port.mk>
