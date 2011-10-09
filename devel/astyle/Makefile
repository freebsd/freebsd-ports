# New ports collection makefile for:	astyle
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	astyle
PORTVERSION=	2.02
CATEGORIES=	devel textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A reindenter and reformatter of C, C++, C\# and Java source code

ALL_TARGET=	astyle
CFLAGS+=	-W -Wall -fno-rtti -fno-exceptions
LDFLAGS+=	-s
MAKE_ARGS+=	CFLAGS="${CFLAGS}"
USE_GMAKE=	yes
USE_GCC=	4.4+

WRKSRC=		${WRKDIR}/astyle/build/gcc

pre-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS,#CFLAGS,; s,g++,${CXX},;' ${WRKSRC}/Makefile

PLIST_FILES=	bin/astyle
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/astyle ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
