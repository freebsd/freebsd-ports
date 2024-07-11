PORTNAME=	libcddb
PORTVERSION=	1.3.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library to access data on a CDDB server
WWW=		https://libcddb.sourceforge.net/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Multiple services have been shutdown and there's no way to easily submit data
EXPIRATION_DATE=2024-07-31

GNU_CONFIGURE=	yes
USES=		iconv libtool localbase pathfix tar:bzip2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-cdio
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
