# New ports collection makefile for:	libshout
# Date created:				06 Jun 2000
# Whom:					Zach Zurflu <zach@pabst.bendnet.com>
#
# $FreeBSD$
#

PORTNAME=	libshout
PORTVERSION=	1.0.7
CATEGORIES=	audio net
#MASTER_SITES=	http://downloads.xiph.org/releases/libshout/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connect and transmit data to an Icecast media streaming server

CONFLICTS=	libshout2-*

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-O20||' ${WRKSRC}/configure

.include <bsd.port.mk>
