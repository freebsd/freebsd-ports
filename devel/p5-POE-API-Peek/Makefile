# New ports collection makefile for:	POE-API-Peek
# Date created:	   11 November 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-API-Peek
DISTVERSION=	2.16_2
PORTEPOCH=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/S/SU/SUNGO
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Peek into the internals of a running POE environment

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Devel/Size.pm:${PORTSDIR}/devel/p5-Devel-Size
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		POE::API::Peek.3

regression-test:
	@(cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} && ${MAKE} test)

.include <bsd.port.mk>
