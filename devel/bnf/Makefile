# New ports collection makefile for:	bnf
# Date created:				22 May 2003
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bnf
PORTVERSION=	1.6.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate C parser given a grammar in BNF notation

GNU_CONFIGURE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/bnf ${PREFIX}/bin/bnf
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/doc/bnf.info ${PREFIX}/info
.endif

post-install:
.if !defined(NOPORTDOCS)
	@install-info ${PREFIX}/info/bnf.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
