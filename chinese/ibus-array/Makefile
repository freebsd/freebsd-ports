PORTNAME=	ibus-array
PORTVERSION=	0.2.2.${SNAPDATE}
CATEGORIES=	chinese

MAINTAINER=	jiashiun@gmail.com
COMMENT=	Array 30 input method for IBus
WWW=		https://github.com/lexical/ibus-array/

LICENSE=	GPLv2

BUILD_DEPENDS=	ibus-daemon:textproc/ibus zh-opencc>=1.0:chinese/opencc
RUN_DEPENDS=	ibus-daemon:textproc/ibus zh-opencc>=1.0:chinese/opencc

USES=		autoreconf gmake gnome libtool pkgconfig python sqlite
USE_GNOME+=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	lexical
GH_TAGNAME=	06146c5e6518ddf813d0ab1789ba84eadbe9d52b
SNAPDATE=	20230502

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
