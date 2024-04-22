PORTNAME=	libpinyin
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	lichray@gmail.com
COMMENT=	Library to deal with pinyin
WWW=		https://github.com/libpinyin/libpinyin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bdb compiler:c++11-lang gmake gnome libtool pathfix pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=CPPFLAGS="-I${LOCALBASE}/include \
		-I${BDB_INCLUDE_DIR}" \
		LDFLAGS="-L${LOCALBASE}/lib -l${BDB_LIB_NAME}"
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

PLIST_SUB+=	VER=${PORTVERSION} \
		ABIVER=15

.include <bsd.port.mk>
