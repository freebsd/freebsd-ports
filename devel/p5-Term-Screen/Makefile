# New ports collection makefile for:	Screen
# Date created:				Dec 17, 2000
# Whom:					Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Term-Screen
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-
DISTNAME=	Screen-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

USE_PERL5=	YES

MAN3=		Term::Screen.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
POD2MAN?=	/usr/bin/pod2man

do-build:
	@${POD2MAN} ${WRKSRC}/Screen.pm > ${WRKSRC}/${MAN3}

do-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN3} ${MAN3PREFIX}/man/man3
	${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Term
	${INSTALL_SCRIPT} ${WRKSRC}/Screen.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Term
	${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/auto/Term/Screen
	${ECHO} '${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Term/Screen.pm' >> \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/auto/Term/Screen/.packlist
	${ECHO} '${MAN3PREFIX}/man/man3/${MAN3}' >> \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/auto/Term/Screen/.packlist

.include <bsd.port.mk>
