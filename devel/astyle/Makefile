# New ports collection makefile for:	astyle
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	astyle
PORTVERSION=	1.15.3
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A reindenter and reformatter of C++, C and Java source code

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-q -aa
EXTRACT_AFTER_ARGS=	-d ${DISTNAME}
CFLAGS+=	"-fpermissive"
ALL_TARGET=	astyle
MAKE_ARGS=	CPPFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/astyle
.if !defined(NOPORTDOCS)
PORTDOCS=	astyle.html astyle_release_notes.html license.html
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/astyle ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
