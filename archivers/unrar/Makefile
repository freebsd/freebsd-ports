# New ports collection makefile for:    unrar
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	unrar
PORTVERSION=	3.60.b3
PORTEPOCH=	3
CATEGORIES+=	archivers
MASTER_SITES=	http://files1.rarlab.com/rar/ \
		http://files2.rarlab.com/rar/ \
		http://files3.rarlab.com/rar/ \
		http://files4.rarlab.com/rar/ \
		http://files5.rarlab.com/rar/ \
		http://files6.rarlab.com/rar/
DISTNAME=	unrarsrc-3.6.3

MAINTAINER?=	ache@FreeBSD.org
COMMENT=	Extract, view & test RAR archives

WRKSRC=		${WRKDIR}/unrar

USE_GMAKE=	yes

post-patch:
	@${SED} -e 's|g++|${CXX}|g' -e 's|-O2|${CXXFLAGS}|g' \
		${WRKSRC}/makefile.unix > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
