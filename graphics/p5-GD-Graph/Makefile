# New ports collection makefile for:	p5-GD-Graph
# Date created:				21 February 2000
# Whom:	      				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	GD-Graph
PORTVERSION=	1.35
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-
DISTNAME=	GDGraph-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/GD/Text/Align.pm:${PORTSDIR}/graphics/p5-GD-TextUtil
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GD::Graph.3 \
		GD::Graph::Data.3 \
		GD::Graph::Error.3 \
		GD::Graph::FAQ.3 \
		GD::Graph::colour.3 \
		GD::Graph::hbars.3

.include <bsd.port.mk>
