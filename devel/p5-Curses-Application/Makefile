# ex:ts=8
# Ports collection makefile for:	p5-Curses-Application
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Curses-Application
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses
PKGNAMEPREFIX=	p5-
DISTNAME=	CursesApplication-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses application development framework

BUILD_DEPENDS=	${SITE_PERL}/Curses/Forms.pm:${PORTSDIR}/devel/p5-Curses-Forms
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Curses::Application.3

.include <bsd.port.mk>
