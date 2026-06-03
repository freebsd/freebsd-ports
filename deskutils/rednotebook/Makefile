PORTNAME=	rednotebook
DISTVERSIONPREFIX=v
DISTVERSION=	2.42
CATEGORIES=	deskutils

MAINTAINER=	cth-freebsd@pm.me
COMMENT=	Personal desktop journaling application written in Python
WWW=		https://rednotebook.app

LICENSE=	GPLv3+

LIB_DEPENDS=	libwebkit2gtk-4.1.so:www/webkit2-gtk@41
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		gettext-tools gnome python
USE_GITHUB=	yes
GH_ACCOUNT=	jendrikseipp
USE_GNOME=	gtk30 gtksourceview3
USE_PYTHON=	distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		ENCHANT NLS
OPTIONS_DEFAULT=	ENCHANT
OPTIONS_SUB=		yes
ENCHANT_DESC=		Use PyEnchant for spell checking
ENCHANT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=1.6:textproc/py-enchant
NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
