# New ports collection makefile for:	tkp4
# Date created:         17 May 2002
# Whom:                 mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	tkp4
PORTVERSION=	1.12
CATEGORIES=	devel tk83 tk84
MASTER_SITES=	http://www.timshel.ca/tkp4/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tcl/Tk frontends to Perforce's p4

RUN_DEPENDS=	wish${TCL_VER}:${PORTSDIR}/x11-toolkits/tk${TCL_DVER} \
		p4:${PORTSDIR}/devel/perforce

NO_BUILD=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
TCL_VER=	8.4
TCL_DVER=	${TCL_VER:S/.//}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tkp4 ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/P4WINdifferences \
		${WRKSRC}/UsingTkP4 ${DOCSDIR}

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|wish|wish${TCL_VER}|' ${WRKSRC}/tkp4
.if defined(PREFIX) && ${PREFIX} != "/usr/local"
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		`${GREP} -Fl /usr/local ${WRKSRC}/*`
.endif

.include <bsd.port.post.mk>

SCRIPTS	!=	d=${DATADIR}; p=${PREFIX}; echo $${d\#\#$${p%%/}/}
DOCS	!=	d=${DOCSDIR}; p=${PREFIX}; echo $${d\#\#$${p%%/}/}
PLIST_SUB+=	SCRIPTS=${SCRIPTS} DOCS=${DOCS}
