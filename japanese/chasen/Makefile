# New ports collection makefile for:	chasen
# Version required:	2.02 + 2.1
# Date created:		21 October 1998
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.2 1999/06/07 09:54:39 sakamoto Exp $
# $FreeBSD$
#

DISTNAME=	chasen-sys2.02-ipadic2.1
PKGNAME=	ja-chasen-2.02
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/lab/nlp/tools/chasen/ \
		http://cactus.aist-nara.ac.jp/~akira-k/cha/arc/

MAINTAINER=	kuriyama@FreeBSD.org

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Text::ChaSen.3

WRKSRC=		${WRKDIR}/chasen-2.02

do-configure:

post-build:
	@${ECHO_MSG} "Making dictionaries"
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} dic
	@${ECHO_MSG} "Making perl5 module"
	@cd ${WRKSRC}/perl; \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL; \
		${SETENV} ${MAKE_ENV} ${MAKE}

post-install:
	@cd ${WRKSRC}/perl; ${SETENV} ${MAKE_ENV} ${MAKE} install

.include <bsd.port.mk>
