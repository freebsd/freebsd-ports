# New ports collection makefile for: p5-SETI-Stats
# Date created: 		18 September 2001
# Whom: 			Eric A. Griff <eric@talesfromthereal.com>
#
# $FreeBSD$
#

PORTNAME=	SETI-Stats
PORTVERSION=	1.06
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/M/MH/MHAMILTON
PKGNAMEPREFIX=	p5-

MAINTAINER=	eric@talesfromthereal.com

PERL_CONFIGURE=	yes
MAN3=		SETI::Stats.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/SETI-Stats
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/SETI-Stats
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/SETI-Stats
.endif

.include <bsd.port.mk>
