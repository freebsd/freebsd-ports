# ex:ts=8
# Ports collection makefile for:	p5-Curses-Application
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Curses-Application
PORTVERSION=	0.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	CursesApplication-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses application development framework

BUILD_DEPENDS=	p5-Curses-Forms>=0:${PORTSDIR}/devel/p5-Curses-Forms
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Curses::Application.3

.include <bsd.port.mk>
