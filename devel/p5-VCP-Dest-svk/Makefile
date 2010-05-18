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
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	VCP destination driver for svn/svk

BUILD_DEPENDS=	${SITE_PERL}/VCP.pm:${PORTSDIR}/devel/p5-VCP-autrijus \
		${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		${SITE_PERL}/SVK.pm:${PORTSDIR}/devel/svk \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		VCP::Dest::svk.3

.include <bsd.port.mk>
