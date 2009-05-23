# New ports collection makefile for:	tkcon
# Date created:         28 Jun 1999
# Whom:                 wghicks@bellsouth.net
#
# $FreeBSD$
#

PORTNAME=	tkcon
PORTVERSION=	2.5
CATEGORIES=	devel tcl tk
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk console for Tcl

NO_BUILD=	yes
USE_TK_WRAPPER=	yes

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%DOCSDIR%%|${DOCSDIR}|g' ${WRKSRC}/${PORTNAME}.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.tcl ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/README.${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
