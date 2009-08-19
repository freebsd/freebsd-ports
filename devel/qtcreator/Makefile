### -*-mode: makefile-*-
# New ports collection makefile for:	qtcreator
# Date created:			  	Thu May  7 15:19:01 EDT 2009
# Whom:					kris@pcbsd.org
#
# $FreeBSD$
#

PORTNAME=	qtcreator
PORTVERSION=	1.2.1
CATEGORIES?=	devel
MASTER_SITES=	http://download.qt.nokia.com/qtcreator/
DISTNAME=	qt-creator-${PORTVERSION}-src

MAINTAINER=	kris@pcbsd.org
COMMENT=	Qt4 IDE

LIB_DEPENDS=	Imath.6:${PORTSDIR}/graphics/ilmbase \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.10:${PORTSDIR}/graphics/jpeg

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build \
		linguist_build assistant_run qt3support \
		dbus designer gui help-tools network script \
		sql svg xml webkit
HAS_CONFIGURE=	yes

QMAKE_ARGS=	-unix -recursive ${QMAKE_PRO}
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
		${QMAKE} -unix CONFIG+="configure" ${QMAKE_PRO}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qtcreator \ 
	    ${PREFIX}/bin/qtcreator
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qtcreator.bin \
	    ${PREFIX}/bin/qtcreator.bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qtcreator_process_stub \
	     ${PREFIX}/bin/qtcreator_process_stub
	${MKDIR} ${PREFIX}/lib/
	cd ${WRKSRC}/lib/ && ${FIND} -d qtcreator | ${CPIO} -dumpl \
	    ${PREFIX}/lib/ >/dev/null
	${MKDIR} ${PREFIX}/share/
	cd ${WRKSRC}/share && ${COPYTREE_SHARE} qtcreator \
	    ${PREFIX}/share/
	${MKDIR} ${PREFIX}/share/doc
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${PREFIX}/share/doc/qtcreator/

.include <bsd.port.mk>
