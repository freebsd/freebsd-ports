# New ports collection makefile for:	uthash
# Date created:				06 May 2012
# Whom:					Ryan Steinmetz <zi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uthash
PORTVERSION=	1.9.6
CATEGORIES=	devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A hash table for C structures

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_BZIP2=	yes
NO_BUILD=	yes

PORTDOCS=	ChangeLog.txt sflogo.txt toc.txt topnav.txt topnav_utarray.txt \
		topnav_utlist.txt topnav_utstring.txt userguide.txt utarray.txt \
		utlist.txt utstring.txt
PLIST_FILES=	include/utarray.h include/uthash.h include/utlist.h \
		include/utstring.h

do-install:
	@${INSTALL_DATA} ${WRKSRC}/src/utarray.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/src/uthash.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/src/utlist.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/src/utstring.h ${PREFIX}/include/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/txt/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
