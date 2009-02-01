# New ports collection makefile for:	DBD::FrontBase
# Date created:		19 Jul 2007
# Whom:			Mitchell Smith <mjs@bur.st>
#
# $FreeBSD$
#

PORTNAME=	DBD-FrontBase
PORTVERSION=	1.39
CATEGORIES=	databases perl5
MASTER_SITES+=	http://www.frontbase.com/download/perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	DBD-FB-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	mjs@bur.st
COMMENT=	DBI driver for FrontBase RDBMS server

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/libFBCAccess.a:${PORTSDIR}/databases/frontbase
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.0+
CFLAGS+=	-I${LOCALBASE}/include

MAN3=		DBD::FB.3

.include <bsd.port.mk>
