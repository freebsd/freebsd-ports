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
MASTER_SITES= 	http://www.tu-ilmenau.de/~gomar/stuff/vcheck/

MAINTAINER=	svenasse@polaris.ca

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	vcheck.1

.include <bsd.port.mk>
