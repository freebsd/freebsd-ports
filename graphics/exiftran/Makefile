PORTNAME=	exiftran
PORTVERSION=	2.14
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kraxel.org/releases/fbida/
DISTNAME=	fbida-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Command line utility to transform jpeg files
WWW=		https://www.kraxel.org/blog/linux/fbida/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:graphics/libexif

USES=		jpeg uidfix xorg
USE_XORG=	pixman

CONFLICTS_INSTALL=	ida

MAKE_ARGS+=	WRKSRC=${WRKSRC} BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/share/man
PLIST_FILES=	bin/exiftran bin/thumbnail.cgi \
		share/man/man1/exiftran.1.gz

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${MKDIR} ${WRKSRC}/build/exiftran ${WRKSRC}/build/thumbnail.cgi
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.exiftran \
		${WRKSRC}/build/exiftran/Makefile
	@${CP} ${FILESDIR}/Makefile.thumbnail.cgi \
		${WRKSRC}/build/thumbnail.cgi/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/exiftran.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/exiftran.1

.include <bsd.port.mk>
