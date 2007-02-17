# New ports collection makefile for:	p5-Acme-Lou
# Date created:		2007-02-06
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Acme-Lou
PORTVERSION=	0.03
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/T/TO/TOMITA
PKGNAMEPREFIX=	ja-p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Let's together with Lou Ohshiba

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		ja-p5-Text-MeCab>=0:${PORTSDIR}/japanese/p5-Text-MeCab
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Acme::Lou.3

.include <bsd.port.mk>
