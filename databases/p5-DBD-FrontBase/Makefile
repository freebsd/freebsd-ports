# Created by: Mitchell Smith <mjs@bur.st>
# $FreeBSD$

PORTNAME=	DBD-FrontBase
PORTVERSION=	1.39
CATEGORIES=	databases perl5
MASTER_SITES+=	http://www.frontbase.com/download/perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	DBD-FB-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	mjs@bur.st
COMMENT=	DBI driver for FrontBase RDBMS server

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/libFBCAccess.a:${PORTSDIR}/databases/frontbase
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CFLAGS+=	-I${LOCALBASE}/include

MAN3=		DBD::FB.3

.include <bsd.port.mk>
