# New ports collection makefile for:	POE-Component-DirWatch
# Date created:	   06 July 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-DirWatch
PORTVERSION=	0.300001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POE directory watcher

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE>=0.12:${PORTSDIR}/devel/p5-POE \
		p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
		p5-MooseX-Types-Path-Class>0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-File-Signature>0:${PORTSDIR}/sysutils/p5-File-Signature
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
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
