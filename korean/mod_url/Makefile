# New ports collection makefile for:	mod_url
# Date created:		13 Apr 2003
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		mod_url
PORTVERSION=		20010905
CATEGORIES=		korean www
MASTER_SITES=		http://kle.kldp.org/apache/
DISTFILES=		${PORTNAME}.c readme.${PORTNAME}

MAINTAINER=		cjh@FreeBSD.org
COMMENT=		Apache module for manipulating euc-kr encoded URL

USE_APACHE=	1.3
USE_ICONV=	yes

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_INC=	${LOCALBASE}/include
AP_LIB=	${LOCALBASE}/lib -liconv

PORTDOCS=	readme.${PORTNAME}

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/${PORTNAME}.c ${_DISTDIR}/readme.${PORTNAME} ${WRKSRC}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
