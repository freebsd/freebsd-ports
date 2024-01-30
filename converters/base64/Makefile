PORTNAME=	base64
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.fourmilab.ch/webtools/base64/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Utility to encode and decode base64 files
WWW=		https://www.fourmilab.ch/webtools/base64/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
ALL_TARGET=	prog
PLIST_FILES=	bin/base64 \
		share/man/man1/base64.1.gz

.include <bsd.port.mk>
