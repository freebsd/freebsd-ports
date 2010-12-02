### -*-mode: makefile-*-
# New ports collection makefile for:	qtcreator
# Date created:			  	Thu May  7 15:19:01 EDT 2009
# Whom:					kris@pcbsd.org
#
# $FreeBSD$
#

PORTNAME=	qtcreator
PORTVERSION=	2.0.1
CATEGORIES=	devel
MASTER_SITES=	http://download.qt.nokia.com/qtcreator/
DISTNAME=	qt-creator-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 IDE

LIB_DEPENDS=	Imath.6:${PORTSDIR}/graphics/ilmbase \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build \
		linguist_build assistant_run qt3support \
		dbus designer gui help-tools network script \
		sql svg xml webkit
HAS_CONFIGURE=	yes

QMAKE_ARGS=	-recursive CONFIG+="configure" ${QMAKE_PRO}
QMAKE_PRO=	qtcreator.pro

MAKE_JOBS_SAFE=	yes

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|lrelease|lrelease-qt4|' \
		${WRKSRC}/share/qtcreator/translations/translations.pro
	@${REINPLACE_CMD} -e 's|lupdate|lupdate-qt4|' \
	    ${WRKSRC}/share/qtcreator/translations/translations.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qtcreator ${PREFIX}/bin/qtcreator
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qtcreator_process_stub ${PREFIX}/bin/qtcreator_process_stub
	${MKDIR} ${PREFIX}/lib/
	cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} qtcreator ${PREFIX}/lib/
	${MKDIR} ${PREFIX}/share/
	cd ${WRKSRC}/share && ${COPYTREE_SHARE} qtcreator ${PREFIX}/share/
	${MKDIR} ${PREFIX}/share/doc
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${PREFIX}/share/doc/qtcreator/

.include <bsd.port.mk>
