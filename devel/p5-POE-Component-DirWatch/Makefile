# New ports collection makefile for:	POE-Component-DirWatch
# Date created:	   06 July 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-DirWatch
PORTVERSION=	0.300000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POE directory watcher

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/MooseX/Types/Path/Class.pm:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		${SITE_PERL}/File/Signature.pm:${PORTSDIR}/sysutils/p5-File-Signature
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=	POE::Component::DirWatch.3 \
	POE::Component::DirWatch::Modified.3 \
	POE::Component::DirWatch::New.3 \
	POE::Component::DirWatch::Role::AIO.3 \
	POE::Component::DirWatch::Role::Signatures.3 \
	POE::Component::DirWatch::Unmodified.3

regression-test:
	@(cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} && ${MAKE} test)

.include <bsd.port.mk>
