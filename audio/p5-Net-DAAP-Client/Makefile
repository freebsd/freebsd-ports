# New ports collection makefile for:	p5-Net-DAAP-Client (formerly p5-dapple)
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DAAP-Client
PORTVERSION=	0.42
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Client for Apple iTunes DAAP service

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5/M4p.pm:${PORTSDIR}/security/p5-Digest-MD5-M4p \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/DAAP/DMAP.pm:${PORTSDIR}/audio/p5-Net-DAAP-DMAP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::DAAP::Client.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again."
.endif

.include <bsd.port.post.mk>
