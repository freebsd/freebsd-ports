# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	knights
PORTVERSION=	2.5.0
PORTREVISION=	8
CATEGORIES=	games kde
MASTER_SITES=	http://dl.dropbox.com/u/2888238/Knights/

MAINTAINER=	syncer@gmail.com
COMMENT=	KDE4 chess interface

RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:games/gnuchess

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4 workspace libkdegames
USE_QT=		qmake_build moc_build rcc_build uic_build

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
