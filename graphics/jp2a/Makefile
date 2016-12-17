# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jp2a
PORTVERSION=	1.0.6
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Converts JPG images to ASCII

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		jpeg tar:bzip2
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-jpeg-prefix=${LOCALBASE} \
		--with-curl-config=${LOCALBASE}/bin/curl-config

PLIST_FILES=	bin/jp2a man/man1/jp2a.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jp2a ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/jp2a.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
