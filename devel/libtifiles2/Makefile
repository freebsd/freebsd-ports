PORTNAME=	libtifiles2
PORTVERSION=	1.1.7
CATEGORIES=	devel
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.18

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	TI calculator file types library

LICENSE=	GPLv2

LIB_DEPENDS=	libticonv.so:converters/libticonv

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf gettext-tools gnome libarchive libtool pkgconfig \
		tar:bzip2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
