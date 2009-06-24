# New ports collection makefile for:	p5-File-Find-Object
# Date created:		2006-07-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	File-Find-Object
PORTVERSION=	0.2.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An object oriented File::Find replacement

RUN_DEPENDS=	p5-Class-XSAccessor>=0:${PORTSDIR}/devel/p5-Class-XSAccessor
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=		File::Find::Object.3 \
		File::Find::Object::Base.3 \
		File::Find::Object::PathComp.3 \
		File::Find::Object::Result.3

.include <bsd.port.mk>
