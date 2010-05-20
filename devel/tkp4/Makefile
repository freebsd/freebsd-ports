# New ports collection makefile for:	tkp4
# Date created:         17 May 2002
# Whom:                 mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	tkp4
PORTVERSION=	1.12
PORTREVISION=	2
CATEGORIES=	devel tk
MASTER_SITES=	http://www.timshel.ca/tkp4/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tcl/Tk frontends to Perforce's p4

RUN_DEPENDS=	p4:${PORTSDIR}/devel/p4

NO_BUILD=	yes
REINPLACE_ARGS=	-i ""
USE_TK_RUN=	yes

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tkp4 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/P4WINdifferences \
		${WRKSRC}/UsingTkP4 ${DOCSDIR}
.endif

post-patch:
	${REINPLACE_CMD} -e 's|wish|wish${TCL_VER}|' ${WRKSRC}/tkp4
.if defined(PREFIX) && ${PREFIX} != "/usr/local"
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		`${GREP} -Fl /usr/local ${WRKSRC}/*`
.endif

.include <bsd.port.mk>
