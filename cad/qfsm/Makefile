# ex:ts=8
# Ports collection makefile for:	qfsm
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qfsm
PORTVERSION=	0.51.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.51
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical tool for designing finite state machines

USE_XORG=	xi
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qt3support svg xml \
		moc_build porting_build qmake_build \
		uic_build uic3_build rcc_build
USE_GNOME=	desktopfileutils
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
INSTALLS_ICONS=	yes

.if !defined(WITH_DEBUG)
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS_RELEASE:STRING="-DNDEBUG"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(/usr/include/.*$$|(|g ; \
		 /^\/usr\/include/d ; \
		 /SET.*CMAKE_BUILD_TYPE/d ; \
		 /SET.*CMAKE_INSTALL_PREFIX/d' ${WRKSRC}/CMakeLists.txt

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} qfsm ${PREFIX}/bin)
	@${MKDIR} ${PREFIX}/share/applications
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} qfsm.desktop \
		${PREFIX}/share/applications)
.for i in 32x32 48x48 64x64
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}/apps
	(cd ${WRKSRC}/desktop/${i}/apps && ${INSTALL_DATA} qfsm.png \
		${PREFIX}/share/icons/hicolor/${i}/apps)
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}/mimetypes
	(cd ${WRKSRC}/desktop/${i}/mimetypes && ${INSTALL_DATA} x-qfsm.png \
		${PREFIX}/share/icons/hicolor/${i}/mimetypes)
.endfor
	@${MKDIR} ${PREFIX}/share/mimelnk/application
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} x-qfsm.desktop \
		${PREFIX}/share/mimelnk/application)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/po && ${INSTALL_DATA} *.qm ${DATADIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/user && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif
	@-update-desktop-database

.include <bsd.port.mk>
