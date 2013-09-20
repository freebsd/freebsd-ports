# Created by: Alex Kapranoff <ka@nadoby.ru>
# $FreeBSD$

PORTNAME=	Gearman-XS
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DSCHOEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	otaviof@gmail.com
COMMENT=	Perl front end for the Gearman C library

LIB_DEPENDS=	gearman:${PORTSDIR}/devel/gearmand

CFLAGS+=	-I${LOCALBASE}/include

USES=		perl5
USE_PERL5=	configure

INSTALL_TARGET=	pure_install

MAN3=		Gearman::XS.3 Gearman::XS::Client.3 \
		Gearman::XS::Job.3 Gearman::XS::Task.3 \
		Gearman::XS::Worker.3

NO_STAGE=	yes
.include <bsd.port.mk>
