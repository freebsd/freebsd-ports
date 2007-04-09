# ex:ts=8
# Ports collection makefile for:	eventxx
# Date created:			Apr 9, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eventxx
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.llucax.com.ar/~luca/eventxx/releases/

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	A C++ wrapper for libevent

LIB_DEPENDS=	event-1.3b.1:${PORTSDIR}/devel/libevent

NO_BUILD=	yes

PLIST_FILES=	include/eventxx

do-install:
	@${INSTALL_DATA} ${WRKSRC}/eventxx ${PREFIX}/include

.include <bsd.port.mk>
