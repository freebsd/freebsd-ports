# New ports collection makefile for:	jp2a
# Date created:		17 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jp2a
PORTVERSION=	1.0.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts JPG images to ASCII

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		curl.5:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg-prefix=${LOCALBASE} --with-curl-config=${LOCALBASE}/bin/curl-config
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
