# New ports collection makefile for:	astyle
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	astyle
PORTVERSION=	1.19
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux

MAINTAINER=	andrew.nau.ua@gmail.com
COMMENT=	A reindenter and reformatter of C, C++, C\# and Java source code

ALL_TARGET=	astyle
CXXFLAGS+=	-fno-rtti -fno-exceptions
LDFLAGS+=	-s
MAKE_ARGS=	CPPFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GCC=	3.3+

WRKSRC=		${WRKDIR}/astyle/src

pre-patch:
	${REINPLACE_CMD} -e \
		's,^ifdef,#ifdef,; \
		s,^else,#else,; \
		s,^endif,#endif,; \
		s,^CPPFLAGS,#CPPFLAGS,; \
		s,^LDFLAGS,#LDFLAGS,;' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,g++,$$(CXX),' ${WRKSRC}/Makefile

PLIST_FILES=	bin/astyle
.if !defined(NOPORTDOCS)
PORTDOCS=	astyle.html astyleX.html astyle_news.html astyle_release_notes.html install.txt license.html
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/astyle ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
