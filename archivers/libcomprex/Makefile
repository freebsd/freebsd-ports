# Created by: ijliao
# $FreeBSD$

PORTNAME=	libcomprex
PORTVERSION=	0.3.3
PORTREVISION=	13
CATEGORIES=	archivers
MASTER_SITES=	SF/gnupdate/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparently handles automatic compression and decompression of files

LICENSE=	LGPL21

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

NLS_USES=	gettext
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
