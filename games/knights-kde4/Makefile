# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	knights
PORTVERSION=	2.5.0
CATEGORIES=	games kde
MASTER_SITES=	http://dl.dropbox.com/u/2888238/Knights/

MAINTAINER=	syncer@gmail.com
COMMENT=	KDE4 chess interface

LIB_DEPENDS=	kdegames:${PORTSDIR}/games/kdegames4
RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:${PORTSDIR}/games/gnuchess

LATEST_LINK=	${PORTNAME}-kde4
MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DBUILD_doc=FALSE
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CMAKE_ARGS+=	-DBUILD_po=FALSE
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} "s/^add_subdirectory( doc )//g" \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
