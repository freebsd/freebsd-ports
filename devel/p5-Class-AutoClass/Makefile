# vim:ts=8
# New ports collection makefile for:	p5-Class-AutoClass
# Date created:				25 November 2004
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Class-AutoClass
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Automatically define simple get and set methods in an inheritance structure

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper

PERL_CONFIGURE=	yes

MAN3=		Class::AutoClass::Root.3 Class::AutoClass.3 Class::AutoClass::Args.3

.include <bsd.port.mk>
