# New ports collection makefile for:   p5-AppConfig-Std
# Date created:                20 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	AppConfig-Std
PORTVERSION=	1.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	AppConfig
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A subclass of AppConfig that provides standard options

BUILD_DEPENDS=	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		AppConfig::Std.3

post-patch:
	${PERL} -pi -e 's|(VERSION_FROM\s+=>\s+)(.*)(,.*)$$|$$1$$2$$3\nMAN3PODS=>{$$2=>q!\\\$$(INST_MAN3DIR)/${MAN3}!},|;' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
