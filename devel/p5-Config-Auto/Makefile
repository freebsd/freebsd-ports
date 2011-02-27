# New ports collection makefile for:	p5-Config-Auto
# Date created:				August 29 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Config-Auto
PORTVERSION=	0.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BI/BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Magical config file parser

BUILD_DEPENDS=	p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-YAML>=0.67:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS=	XMLSIMPLE "Support for XML config files" off

.include <bsd.port.pre.mk>

.ifdef(WITH_XMLSIMPLE)
BUILD_DEPENDS+=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS+=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
.endif

MAN3=		Config::Auto.3

.include <bsd.port.post.mk>
