# New ports collection makefile for:	p5-GIFgraph
# Date created:				Nov 9, 1998
# Whom:					laskavy@gambit.msk.su
#
# $FreeBSD$
#

PORTNAME=	GIFgraph
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GIFgraph
PKGNAMEPREFIX=	p5-
DISTNAME=	GIFgraph-${PORTVERSION}

MAINTAINER=	ls@gambit.com.ru

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GIFgraph.3 GIFgraph::colour.3

post-patch:
	find ${WRKSRC} -name '*.orig' -delete

.include <bsd.port.mk>
