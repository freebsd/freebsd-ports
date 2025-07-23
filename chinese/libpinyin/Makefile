PORTNAME=	libpinyin
DISTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES=	chinese textproc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/ \
		SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	lichray@gmail.com
COMMENT=	Library to deal with pinyin
WWW=		https://github.com/libpinyin/libpinyin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

USES=		compiler:c++11-lang gmake gnome libtool localbase:ldflags \
		pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-dbm=KyotoCabinet

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

PLIST_SUB+=	VER=${PORTVERSION} \
		ABIVER=15

.include <bsd.port.mk>
