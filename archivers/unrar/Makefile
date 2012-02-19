# New ports collection makefile for:    unrar
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	unrar
PORTVERSION=	4.10
PORTREVISION=	1
PORTEPOCH=	5
CATEGORIES+=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/ \
		LOCAL/sunpoet
DISTNAME=	unrarsrc-4.1.4

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT=	Extract, view & test RAR archives

CONFLICTS?=	zh-unrar-[0-9].* unrar-iconv-[0-9].*

MAKEFILE=	makefile.unix
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/unrar
PORTDOCS=	license.txt readme.txt

post-patch:
	@${REINPLACE_CMD} -e '/^CXX/ s|^|#|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
