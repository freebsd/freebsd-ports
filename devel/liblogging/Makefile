# New ports collection makefile for:	liblogging
# Date created:		9 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liblogging
PORTVERSION=	0.7.1
CATEGORIES=	devel
MASTER_SITES=	CENKES http://download.rsyslog.com/liblogging/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use system logging library

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

post-patch:
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/s|=.*| \
		= ${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
