# New ports collection makefile for:	p5-Filesys-Virtual-DAAP
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Virtual-DAAP
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Present a DAAP share as a VFS

RUN_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Filesys/Virtual.pm:${PORTSDIR}/devel/p5-Filesys-Virtual \
		${SITE_PERL}/Filesys/Virtual/Plain.pm:${PORTSDIR}/devel/p5-Filesys-Virtual-Plain \
		${SITE_PERL}/Net/DAAP/Client.pm:${PORTSDIR}/audio/p5-Net-DAAP-Client
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Filesys::Virtual::DAAP.3

.include <bsd.port.mk>
