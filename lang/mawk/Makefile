# ex:ts=8
# Ports collection makefile for:  mawk
# Date created:			  24 Dec 1998
# Whom:				  Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	mawk
PORTVERSION=	1.3.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.whidbey.net/pub/brennan/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar.gz

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	yes
ALL_TARGET=

MAN1=		mawk.1

pre-configure:
	${PERL} -pi.orig -e 's:/usr/local:${PREFIX}:' ${WRKSRC}/config.user

.include <bsd.port.mk>
