# New ports collection makefile for:	p5-Parse-RecDescent
# Date created:				July 9th 1999
# Whom:	      				Jerry Hicks <wghicks@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	Parse-RecDescent
PORTVERSION=	1.96.0
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DC/DCONWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.Org
COMMENT=	A recursive descent parsing framework for Perl

BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Parse::RecDescent.3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/tutorial/* ${DOCSDIR}/tutorial
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500900
RUN_DEPENDS+=	p5-version>=0:${PORTSDIR}/devel/p5-version
.endif

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced
.endif

.include <bsd.port.post.mk>
