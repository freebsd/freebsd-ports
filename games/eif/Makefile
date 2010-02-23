# New ports collection makefile for:	eif
# Date created:				4 March 2003
# Whom:					johans
#
# $FreeBSD$
#

PORTNAME=	eif
PORTVERSION=	1.3.4
CATEGORIES=	games ipv6
MASTER_SITES=	http://www.stack.nl/~marcolz/empire/ \
		ftp://ftp.stack.nl/pub/users/johans/eif/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Empire text client

MAN1=		eif.1

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/curout_isapipe/d' ${WRKSRC}/src/data.h

.include <bsd.port.post.mk>
