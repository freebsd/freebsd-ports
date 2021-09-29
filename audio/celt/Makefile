# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>

PORTNAME=	celt
PORTVERSION=	0.11.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/celt/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	The CELT ultra-low delay audio codec

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Deprecated and considered obsolete by upstream in 2016 in favour of (lib)opus
EXPIRATION_DATE=2021-12-31

LIB_DEPENDS=	libogg.so:audio/libogg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE}
USE_LDCONFIG=	yes
USES=		gmake libtool:keepla pathfix
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
