# New ports collection Makefile for:	tinows
# Date created:				2011-10-18
# Whom:					Joris Dedieu <joris.dedieu@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		tinyows
PORTVERSION=		1.0.0
PORTREVISION=		2
CATEGORIES=		graphics www geography
MASTER_SITES=		http://tinyows.org/release/

MAINTAINER=		joris.dedieu@gmail.com
COMMENT=		High Performance WFS-T server

LIB_DEPENDS=		xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=		${LOCALBASE}/lib/postgresql/postgis-1.5.so:${PORTSDIR}/databases/postgis

USE_BZIP2=		YES
GNU_CONFIGURE=		YES

OPTIONS_DEFINE=		FASTCGI
OPTIONS_DEFAULT=	FASTCGI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFASTCGI}
BUILD_DEPENDS+=	${LOCALBASE}/bin/cgi-fcgi:${PORTSDIR}/www/fcgi
CONFIGURE_ARGS+=	--with-fastcgi=${LOCALBASE}
.endif

post-install:
	${MKDIR} ${WWWDIR}/cgi-bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tinyows ${WWWDIR}/cgi-bin/tinyows

.include <bsd.port.mk>
