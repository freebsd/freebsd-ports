PORTNAME=	libcomprex
PORTVERSION=	0.3.3
PORTREVISION=	14
CATEGORIES=	archivers
MASTER_SITES=	SF/gnupdate/${PORTNAME}/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Transparently handles automatic compression and decompression of files
WWW=		https://gnupdate.sourceforge.net/components/libcomprex/index.xml

LICENSE=	LGPL21

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext localbase:ldflags
NLS_CONFIGURE_ENABLE=	nls
NLS_LDFLAGS=	-lintl

.include <bsd.port.mk>
