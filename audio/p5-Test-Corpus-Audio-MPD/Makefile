# New ports collection makefile for:	Test-Corpus-Audio-MPD
# Date created:				18 Sep, 2010
# Whom:	      				Wen Heping <wen@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Corpus-Audio-MPD
PORTVERSION=	1.113282
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automate launching of fake mdp for testing purposes

BUILD_DEPENDS=	p5-File-ShareDir-PathClass>0:${PORTSDIR}/devel/p5-File-ShareDir-PathClass \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Test::Corpus::Audio::MPD.3

.include <bsd.port.mk>
