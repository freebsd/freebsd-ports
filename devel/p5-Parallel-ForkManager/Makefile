# New ports collection makefile for:	p5-Parallel-ForkManager
# Date created:				October 26th 2002
# Whom:					Nicolas Jombart <Nicolas.Jombart@hsc-labs.com>
#
# $FreeBSD$

PORTNAME=	Parallel-ForkManager
PORTVERSION=	0.7.5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://hacks.dlux.hu/Parallel-ForkManager/download/
MASTER_SITE_SUBDIR=	Parallel
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A simple parallel processing fork manager

PERL_CONFIGURE=	YES

MAN3=		Parallel::ForkManager.3

EXAMPLES=	samples/*

post-extract:
	@${MV} ${WRKSRC}/ForkManager ${WRKSRC}/samples

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
