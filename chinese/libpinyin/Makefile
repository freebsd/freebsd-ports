PORTNAME=	libpinyin
PORTVERSION=	2.6.2
CATEGORIES=	chinese textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	lichray@gmail.com
COMMENT=	Library to deal with pinyin

LICENSE=	GPLv2

USES=		bdb compiler:c++11-lang gmake gnome libtool pathfix pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=CPPFLAGS="-I${LOCALBASE}/include \
		-I${BDB_INCLUDE_DIR}" \
		LDFLAGS="-L${LOCALBASE}/lib -l${BDB_LIB_NAME}"
INSTALL_TARGET=install-strip

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

PLIST_SUB+=	VER=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpinyin.so.13.0.0

.include <bsd.port.mk>
