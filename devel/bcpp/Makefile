# New ports collection makefile for:	bcpp
# Date created:			07 November 2001
# Whom:				Mike Buchanon <buchanon@msu.edu>
#
# $FreeBSD$
#

PORTNAME=	bcpp
PORTVERSION=	20050725
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/bcpp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	buchanon@msu.edu
COMMENT=	A utility similar to indent for C++ code

WRKSRC=		${WRKDIR}/${DISTNAME}
MAKEFILE=	makefile
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/code/bcpp.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/code/${PORTNAME}.cfg \
		${PREFIX}/etc/${PORTNAME}.cfg.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/hirachy.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/txtdocs/manual.txt ${DOCSDIR}
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
