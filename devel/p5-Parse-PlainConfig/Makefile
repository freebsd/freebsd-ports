# New ports collection makefile for:	p5-Parse-PlainConfig
# Date created:				December 2nd 2010
# Whom:	      				Peter Vereshagin <peter@vereshagin.org>
#
# $FreeBSD$
#

PORTNAME=	Parse-PlainConfig
PORTVERSION=	2.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	peter@vereshagin.org
COMMENT=	Perl5 module to use plain config files

RUN_DEPENDS=	p5-Paranoid>0:${PORTSDIR}/devel/p5-Paranoid \
		p5-Text-ParseWords>0:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Text-Tabs+Wrap>0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap

PERL_CONFIGURE=	yes

MAN3=		Parse::PlainConfig.3

.include <bsd.port.mk>
