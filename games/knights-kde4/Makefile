# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	knights
PORTVERSION=	2.5.0
PORTREVISION=	6
CATEGORIES=	games kde
MASTER_SITES=	http://dl.dropbox.com/u/2888238/Knights/

MAINTAINER=	syncer@gmail.com
COMMENT=	KDE4 chess interface

RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:games/gnuchess

LICENSE=	GPLv2

USES=		cmake:outsource tar:bzip2
USE_KDE4=	kdelibs automoc4 workspace libkdegames
USE_QT4=	qmake_build moc_build rcc_build uic_build

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DBUILD_doc=FALSE
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
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
