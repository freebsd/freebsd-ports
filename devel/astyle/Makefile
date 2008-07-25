# New ports collection makefile for:	astyle
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	astyle
PORTVERSION=	1.21
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}__linux

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A reindenter and reformatter of C, C++, C\# and Java source code

ALL_TARGET=	astyle
CFLAGS+=	-W -Wall -fno-rtti -fno-exceptions
LDFLAGS+=	-s
MAKE_ARGS+=	CFLAGS="${CFLAGS}"
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/astyle/build
ALL_TARGET=	release

pre-patch:
	${REINPLACE_CMD} -e 's,^CFLAGS,#CFLAGS,; s,g++,${CXX},;' ${WRKSRC}/Makefile

PLIST_FILES=	bin/astyle
.if !defined(NOPORTDOCS)
PORTDOCS=	astyle.html astyleX.html astyle_news.html install.html license.html astyle_notes.html index.html
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/astyle ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
