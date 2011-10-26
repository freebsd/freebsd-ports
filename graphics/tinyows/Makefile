# New ports collection Makefile for:	tinows
# Date created:				2011-10-18
# Whom:					Joris Dedieu <joris.dedieu@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		tinyows
PORTVERSION=		1.0.0
CATEGORIES=		graphics www geography
MASTER_SITES=		http://tinyows.org/tracdocs/release/

MAINTAINER=		joris.dedieu@nfrance.com
COMMENT=		High Performance WFS-T server

LIB_DEPENDS=		xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=		${LOCALBASE}/lib/postgresql/postgis-1.5.so:${PORTSDIR}/databases/postgis

USE_BZIP2=		YES
WRKSRC=      		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=		YES

OPTIONS=		FASTCGI "Support FASTCGI" on \

.include <bsd.port.pre.mk>

.if defined(WITH_FASTCGI)
BUILD_DEPENDS+=         ${LOCALBASE}/bin/cgi-fcgi:${PORTSDIR}/www/fcgi
CONFIGURE_ARGS+=        --with-fastcgi=${LOCALBASE}
.endif

post-install:
	${MKDIR} ${WWWDIR}/cgi-bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tinyows ${WWWDIR}/cgi-bin/tinyows

.include <bsd.port.post.mk>
