PORTNAME=	libpuzzle
PORTVERSION=	0.11
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/libpuzzle/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to find similar pictures
WWW=		http://libpuzzle.pureftpd.org/project/libpuzzle

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgd.so:graphics/gd

USES=		autoreconf libtool tar:bzip2 localbase
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	GDLIBCONFIG=/usr/bin/true
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS README THANKS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
