# New ports collection makefile for:	qtemu
# Date created:		2007-03-20
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qtemu
PORTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A Qt4 front-end to Qemu

USE_BZIP2=	yes
USE_QT4=	gui xml uic_build moc_build qmake_build rcc_build
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

DESKTOP_ENTRIES="QtEmu" "QEMU frontend" "" \
		"qtemu" "" false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
#USE_QT4+=	linguist
BUILD_DEPENDS+=	${LOCALBASE}/bin/lupdate-qt4:${PORTSDIR}/devel/qt4-linguist
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

do-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/lrelease-qt4 -verbose qtemu.pro \
	&& ${SETENV} ${CONFIGURE_ENV} ${QMAKE})

post-configure:
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|^LINK .*|LINK=${CXX}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtemu ${PREFIX}/bin/qtemu
.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/translations/ && ${COPYTREE_SHARE} 'qtemu*.qm' ${DATADIR}/translations)
.endif
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/help/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
