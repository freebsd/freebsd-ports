# New ports collection makefile for:	p5-Gearman-XS
# Date created:				July 3rd 2009
# Whom:	      				Alex Kapranoff <ka@nadoby.ru>
#
# $FreeBSD$
#

PORTNAME=	Gearman-XS
PORTVERSION=	0.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ka@nadoby.ru
COMMENT=	Perl front end for the Gearman C library

LIB_DEPENDS=	gearman.1:${PORTSDIR}/devel/gearmand

CFLAGS+=	-I${LOCALBASE}/include

PERL_CONFIGURE=	yes

INSTALL_TARGET=	pure_install

MAN3=		Gearman::XS.3 Gearman::XS::Client.3 \
		Gearman::XS::Job.3 Gearman::XS::Task.3 \
		Gearman::XS::Worker.3

.include <bsd.port.mk>
