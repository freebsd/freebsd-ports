# New ports collection makefile for:	p5-Metabase-Client-Simple
# Date created:		2011-02-05
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Metabase-Client-Simple
PORTVERSION=	0.008
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Client that submits to Metabase servers

BUILD_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Metabase-Fact>0:${PORTSDIR}/devel/p5-Metabase-Fact
RUN_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Metabase-Fact>0:${PORTSDIR}/devel/p5-Metabase-Fact \
		p5-Crypt-SSLeay>0:${PORTSDIR}/security/p5-Crypt-SSLeay

PERL_CONFIGURE=	yes

MAN3=	Metabase::Client::Simple.3

.include <bsd.port.mk>
