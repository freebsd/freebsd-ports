# New ports collection makefile for:	p5-Filesys-Virtual-DAAP
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Virtual-DAAP
PORTVERSION=	0.03
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filesys
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Present a DAAP share as a VFS

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Filesys/Virtual.pm:${PORTSDIR}/devel/p5-Filesys-Virtual \
		${SITE_PERL}/Net/DAAP/Client.pm:${PORTSDIR}/audio/p5-Net-DAAP-Client
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Filesys::Virtual::DAAP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again."
.endif

.include <bsd.port.post.mk>
