# New ports collection makefile for:	devel/p5-VCP-Dest-svk
# Date created:				Jul 19 2004
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	VCP-Dest-svk
PORTVERSION=	0.29
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	VCP destination driver for svn/svk

BUILD_DEPENDS=	p5-VCP-autrijus>=0:${PORTSDIR}/devel/p5-VCP-autrijus \
		p5-subversion>=0:${PORTSDIR}/devel/p5-subversion \
		svk>=0:${PORTSDIR}/devel/svk \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		VCP::Dest::svk.3

.include <bsd.port.mk>
