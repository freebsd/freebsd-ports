# ex:ts=8
# Ports collection makefile for:	qfsm
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qfsm
PORTVERSION=	0.50
CATEGORIES=	cad
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical tool for designing finite state machines

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qt3support svg xml \
		moc_build porting_build qmake_build uic_build uic3_build
INSTALLS_ICONS=	yes
USE_XORG=	xi

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/qfsm.pro

do-configure:
	@cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS} qfsm.pro

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qfsm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/user && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
