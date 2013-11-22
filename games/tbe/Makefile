# $FreeBSD$

PORTNAME=	tbe
PORTVERSION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Milestone%20${PORTVERSION}
DISTNAME=	TheButterflyEffect-M${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The Butterfly Effect

BUILD_DEPENDS=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

USES=		qmake
USE_GMAKE=	yes
USE_QT4=	corelib gui moc_build rcc_build svg uic_build xml
WRKSRC=		${WRKDIR}/TheButterflyEffect-M${PORTVERSION}rc3

PLIST_FILES=	bin/tbe
PORTDATA=	*

DESKTOP_ENTRIES="The Butterfly Effect" "Inspired by The Incredible Machine" \
		"${DATADIR}/images/tbe-icon.png" \
		"${PREFIX}/bin/tbe" "LogicGame;Game;" false

NO_STAGE=	yes
post-patch:
		@${REINPLACE_CMD} 's/ make/ ${GMAKE}/' \
			${WRKSRC}/3rdParty/Makefile
		@${REINPLACE_CMD} 's/debug/release link_prl/' ${WRKSRC}/tbe.pro
		@${SED} 's:%%DATADIR:QString("${DATADIR}"):'  \
			${WRKSRC}/src/tbe_global.h.in > ${WRKSRC}/src/tbe_global.h
		@${REINPLACE_CMD} -e '/ensure that no-one tries to build/,$$d' \
			${WRKSRC}/tbe.pro

pre-configure:
		# This is supposedly done by the ./configure script
		@cd ${WRKSRC}/3rdParty && ${GMAKE}

do-install:
		@${MKDIR} ${PREFIX}/bin
		@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
		@${MKDIR} ${DATADIR}
		@cd ${WRKSRC} && ${PAX} -rw images levels ${DATADIR}

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
