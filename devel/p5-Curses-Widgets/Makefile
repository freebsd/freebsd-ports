# New ports collection makefile for:	p5-Curses-Widgets
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Curses-Widgets
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses
PKGNAMEPREFIX=	p5-
DISTNAME=	curses_widgets_${PORTVERSION:S/./_/}

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/curses_widgets-${PORTVERSION}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Curses::Widgets.3

.include <bsd.port.mk>
