# New ports collection makefile for:	Test-Corpus-Audio-MPD
# Date created:				18 Sep, 2010
# Whom:	      				Wen Heping <wen@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Corpus-Audio-MPD
PORTVERSION=	1.110710
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JQUELIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Automate launching of fake mdp for testing purposes

BUILD_DEPENDS=	p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		devel/p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	YES

MAN3=		Test::Corpus::Audio::MPD.3

.include <bsd.port.mk>
