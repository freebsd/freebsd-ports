# New ports collection makefile for:	p5-Parallel-ForkManager
# Date created:				October 26th 2002
# Whom:					Nicolas Jombart <Nicolas.Jombart@hsc-labs.com>
#
# $FreeBSD$

PORTNAME=	Parallel-ForkManager
PORTVERSION=	0.7.4
CATEGORIES=	devel perl5
MASTER_SITES=	http://hacks.dlux.hu/Parallel-ForkManager/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	david@bushong.net

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Parallel::ForkManager.3

EXAMPLES=	samples/*

post-extract:
	@${MV} ${WRKSRC}/ForkManager ${WRKSRC}/samples

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/perl5/${PORTNAME}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/perl5/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
