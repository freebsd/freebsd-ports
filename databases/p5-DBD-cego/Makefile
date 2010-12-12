# New ports collection makefile for:	p5-DBD-cego
# Date created:				Jul  2, 2010
# Whom:					Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	DBD-cego
PORTVERSION=	1.1.14
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.lemke-it.com/
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	A Cego DBI driver for Perl 5

BUILD_DEPENDS=	p5-DBI>=1.61:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	cego.1:${PORTSDIR}/databases/cego

LICENSE=	GPLv2
PERL_CONFIGURE=	yes
CC:=		${CXX}

MAN3=		DBD::Cego.3

.include <bsd.port.mk>
