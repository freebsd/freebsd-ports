# New ports collection makefile for:	typist
# Version required:		2.0
# Date created:			26 May 1997
# Whom:				Satoshi TAOKA
#
# $Id: Makefile,v 1.1.1.1 1997/06/24 05:29:02 max Exp $
#

DISTNAME=	typist2.0
PKGNAME=	ja-typist-2.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://tuba.csedu.kobe-u.ac.jp/pub/UNIX/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAN1=		typist.1

post-install:
	@strip ${PREFIX}/bin/typist
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/typist
	${INSTALL_DATA} ${WRKSRC}/../doc/INSTALL.txt $(PREFIX)/share/doc/typist
	${INSTALL_DATA} ${WRKSRC}/../doc/README.J $(PREFIX)/share/doc/typist
	${INSTALL_DATA} ${WRKSRC}/../doc/README.orig $(PREFIX)/share/doc/typist
.endif

.include <bsd.port.mk>
