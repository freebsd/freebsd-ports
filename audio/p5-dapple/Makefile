# New ports collection makefile for:	p5-dapple
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dapple
PORTVERSION=	0.21
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/G/GN/GNAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	DAAP library for Perl

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::DAAP::Client.3 \
		Net::DAAP::DMAP.3

.include <bsd.port.pre.mk>

post-patch:
	@ ${PERL} -pi -e 's/Term::Readline/Term::ReadLine/;' \
		${WRKSRC}/examples/itshell
.if ${PERL_LEVEL} <= 500503
	@ ${PERL} -pi -e 's/^our ([@%]\w+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/lib/Net/DAAP/DMAP.pm
.endif

.include <bsd.port.post.mk>
