# New ports collection makefile for:	bcpp
# Date created:			07 November 2001
# Whom:				Mike Buchanon <buchanon@msu.edu>
#
# $FreeBSD$
#

PORTNAME=	bcpp
PORTVERSION=	20020518
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/bcpp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	buchanon@msu.edu
COMMENT=	A utility similar to indent for C++ code

WRKSRC=		${WRKDIR}/${DISTNAME}/code
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/bcpp.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg \
		${PREFIX}/etc/${PORTNAME}.cfg.sample

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/txtdocs/hirachy.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/txtdocs/manual.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO} "************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO} "************************************************************"

.include <bsd.port.mk>
