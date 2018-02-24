# Created by: roam@orbitel.bg
# $FreeBSD$

PORTNAME=	ghtool
PORTVERSION=	1.0
CATEGORIES=	dns
MASTER_SITES=	SF/gh-tool/gh-tool/1
DISTNAME=	ghmain.c
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line interface to the resolver library

LICENSE=	NONE

PLIST_FILES=	bin/gh

do-extract:
	@${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKDIR}/gh ${WRKDIR}/ghmain.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/gh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
