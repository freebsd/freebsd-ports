# New ports collection makefile for:	p5-DBD-cego
# Date created:				Jul  2, 2010
# Whom:					Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	DBD-cego
PORTVERSION=	1.1.9
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.lemke-it.com/
PKGNAMEPREFIX=	p5-
DISTNAME=	DBD-cego-${PORTVERSION}

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	A Cego DBI driver for Perl 5

BUILD_DEPENDS=	p5-DBI>=1.61:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	cego.1:${PORTSDIR}/databases/cego

LICENSE=	GPLv2
WRKSRC=		${WRKDIR}/DBD-cego
PERL_CONFIGURE=		yes
CC=			g++

MAN3=		DBD::Cego.3

.include <bsd.port.mk>
