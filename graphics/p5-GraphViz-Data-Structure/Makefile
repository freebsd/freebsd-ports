# ex:ts=8
# Ports collection makefile for:	p5-GraphViz-Data-Structure
# Date created:			Sep 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	GraphViz-Data-Structure
PORTVERSION=	0.07
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GraphViz
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Visualise data structures

BUILD_DEPENDS=	${PERL_SITELIBDIR}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz \
		${PERL_SITELIBDIR}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_SITELIBDIR=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	GraphViz::Data::Structure.3

.include <bsd.port.mk>
