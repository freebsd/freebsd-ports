# New ports collection makefile for:	Inline::Tcl
# Date created:		14 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Inline-Tcl
PORTVERSION=	0.09
CATEGORIES=	devel perl5 tcl83
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Inline
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Inline.pm:${PORTSDIR}/devel/p5-Inline
LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Inline::Tcl.3

.include <bsd.port.mk>
