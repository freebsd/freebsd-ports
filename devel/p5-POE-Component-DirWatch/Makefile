# New ports collection makefile for:	POE-Component-DirWatch
# Date created:	   06 July 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-DirWatch
PORTVERSION=	0.200000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE directory watcher

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::DirWatch.3 \
	POE::Component::DirWatch::Modified.3 \
	POE::Component::DirWatch::New.3 \
	POE::Component::DirWatch::Role::AIO.3 \
	POE::Component::DirWatch::Role::Signatures.3 \
	POE::Component::DirWatch::Unmodified.3

.include <bsd.port.mk>
