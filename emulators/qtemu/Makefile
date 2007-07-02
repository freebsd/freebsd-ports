# New ports collection makefile for:	qtemu
# Date created:		2007-03-20
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qtemu
PORTVERSION=	1.0.3
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	makc@issp.ac.ru
COMMENT=	A Qt4 front-end to Qemu

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml uic moc qmake rcc
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

DESKTOP_ENTRIES="QtEmu" "QEMU frontend" "" \
		"qtemu" "" false

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
#QT_COMPONENTS+=	linguist
BUILD_DEPENDS+=	${LOCALBASE}/bin/lupdate-qt4:${PORTSDIR}/devel/qt4-linguist
QTI_LANG=	cz de es ru tr
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE})

post-configure:
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|^LINK .*|LINK=${CXX}|; \
		 s|-pipe||; \
		 s|^\(CFLAGS .*= \)|\1${CFLAGS}|; \
		 s|^\(CXXFLAGS = \)|\1${CXXFLAGS}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtemu ${PREFIX}/bin/qtemu
.if !defined(WITHOUT_NLS)
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/translations/ && ${COPYTREE_SHARE} '*.qm' ${DATADIR}/translations)
.endif
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/help/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
