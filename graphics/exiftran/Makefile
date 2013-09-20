# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exiftran
DISTNAME=	fbida-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
PORTVERSION=	2.09
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kraxel.org/releases/fbida/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Command line utility to transform jpeg files

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		jpeg:${PORTSDIR}/graphics/jpeg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_ARGS+=	WRKSRC=${WRKSRC} BINDIR=${PREFIX}/bin MANDIR=${MANPREFIX}/man

PLIST_FILES=	bin/exiftran bin/thumbnail.cgi
MAN1=		exiftran.1

NO_STAGE=	yes
post-patch:
	@${MKDIR} ${WRKSRC}/build/exiftran ${WRKSRC}/build/thumbnail.cgi
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.exiftran \
		${WRKSRC}/build/exiftran/Makefile
	@${CP} ${FILESDIR}/Makefile.thumbnail.cgi \
		${WRKSRC}/build/thumbnail.cgi/Makefile

post-install:
	@${INSTALL_MAN} ${WRKSRC}/exiftran.man \
		${MANPREFIX}/man/man1/exiftran.1

.include <bsd.port.mk>
