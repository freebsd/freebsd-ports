# New ports collection makefile for:    unrar
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	unrar
PORTVERSION=	4.00.b4
PORTEPOCH=	5
CATEGORIES+=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/
DISTNAME=	unrarsrc-4.0.4

MAINTAINER?=	ache@FreeBSD.org
COMMENT=	Extract, view & test RAR archives

WRKSRC=		${WRKDIR}/unrar

CONFLICTS?=	zh-unrar-[0-9].* unrar-iconv-[0-9].*
USE_GMAKE=	yes

PLIST_FILES=	bin/unrar
PORTDOCS=	license.txt readme.txt

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
