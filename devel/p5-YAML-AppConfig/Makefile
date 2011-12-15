# New ports collection makefile for:	YAML::AppConfig
# Date created:		26 Aug 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	YAML-AppConfig
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to manage configuration files with YAML

RUN_DEPENDS=	\
	p5-YAML>=0.38:${PORTSDIR}/textproc/p5-YAML \
	p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	YAML::AppConfig.3

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM}

.include <bsd.port.mk>
