# ex:ts=8
# New ports collection makefile for:	vcheck
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vcheck
PORTVERSION=	1.2.1
CATEGORIES=	ftp
MASTER_SITES= 	http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Automatically check for and download most recent versions of software

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	vcheck.1

.include <bsd.port.mk>
