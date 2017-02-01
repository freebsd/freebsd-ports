# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jp2a
PORTVERSION=	1.0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Converts JPG images to ASCII

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		autoreconf jpeg
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cslarsen

CONFIGURE_ARGS=	--with-jpeg-prefix=${LOCALBASE} \
		--with-curl-config=${LOCALBASE}/bin/curl-config

PLIST_FILES=	bin/jp2a man/man1/jp2a.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jp2a ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/jp2a.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
