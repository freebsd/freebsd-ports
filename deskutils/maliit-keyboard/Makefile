PORTNAME=	keyboard
DISTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	deskutils kde
PKGNAMEPREFIX=	maliit-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Virtual keyboard based on Maliit framework
WWW=		https://maliit.github.io/

BUILD_DEPENDS=	hunspell:textproc/hunspell
LIB_DEPENDS=	libmaliit-plugins.so:deskutils/maliit-framework \
		libpresage.so:deskutils/presage \
		libQt5Feedback.so:deskutils/qtfeedback \
		libhunspell-1.7.so:textproc/hunspell

USES=		cmake gettext gnome pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	maliit
USE_GNOME=	glib20
GLIB_SCHEMAS=	org.maliit.keyboard.maliit.gschema.xml
USE_QT=		core dbus declarative gui multimedia network quickcontrols2 \
		buildtools:build qmake:build
CMAKE_OFF=	enable-tests
CMAKE_ARGS=	-DHUNSPELL_DICT_PATH=${PREFIX}/share/hunspell

OPTIONS_DEFINE=	ANTHY CHEWING PINYIN
OPTIONS_SUB=	yes

ANTHY_DESC=		Japanese language support
CHEWING_DESC=		Chinese language support via chewing
PINYIN_DESC=		Chinese language support via pinyin

ANTHY_LIB_DEPENDS=	libanthy-unicode.so:japanese/anthy-unicode
ANTHY_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Anthy
CHEWING_LIB_DEPENDS=	libchewing.so:chinese/libchewing
CHEWING_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Chewing
PINYIN_LIB_DEPENDS=	libpinyin.so:chinese/libpinyin
PINYIN_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Pinyin

.include <bsd.port.mk>
