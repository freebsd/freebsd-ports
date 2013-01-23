# New ports collection makefile for:	qtcreator
# Date created:			  	2009-05-07
# Whom:					kris@pcbsd.org
#
# $FreeBSD$
#

PORTNAME=	qtcreator
PORTVERSION=	2.5.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://download.qt.nokia.com/qtcreator/
DISTNAME=	qt-creator-${PORTVERSION}-src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Creator IDE and tools

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_QT4=	qmake_build moc_build rcc_build uic_build \
		linguist_build assistant_run qt3support \
		dbus designer gui help-tools_build network script \
		sql svg xml webkit qdoc3_build
HAS_CONFIGURE=	yes
MAKE_ENV+=	INSTALL_ROOT=${PREFIX}
ALL_TARGET=	all docs
INSTALL_TARGET=	install install_docs

QMAKE_ARGS=	-recursive CONFIG+="configure" ${QMAKE_PRO}
QMAKE_PRO=	${WRKSRC}/${PORTNAME}.pro

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

CONFIGURE_WRKSRC=	${WRKDIR}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}

DESKTOP_ENTRIES=	"Qt Creator" "${COMMENT}" "${PORTNAME}" \
			"${PORTNAME}" "" false

post-patch:
	${REINPLACE_CMD} -e 's|lrelease|lrelease-qt4|' \
		${WRKSRC}/share/qtcreator/translations/translations.pro
	${REINPLACE_CMD} -e 's|lupdate|lupdate-qt4|' \
	    ${WRKSRC}/share/qtcreator/translations/translations.pro

do-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}
	cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

.include <bsd.port.mk>
