# New ports collection makefile for:	jlj
# Date created:				29 April 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	jlj
PORTVERSION=	2.7
CATEGORIES=	deskutils net
MASTER_SITES=	http://www.cis.rit.edu/~jerry/Software/perl/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Jerry's command-line LiveJournal.com entry system

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e 's!/usr/bin/perl!${PERL}!' ${WRKSRC}/jlj.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jlj.pl ${PREFIX}/bin/jlj
	@${MKDIR} ${PREFIX}/share/examples/jlj
	${INSTALL_DATA} ${WRKSRC}/.livejournal.rc \
		${PREFIX}/share/examples/jlj/dot.livejournal.rc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/jlj
	${INSTALL_DATA} ${WRKSRC}/README.JLJ ${PREFIX}/share/doc/jlj/README
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
