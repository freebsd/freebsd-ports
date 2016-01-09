# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	vym
PORTVERSION=	2.2.4
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	SF/vym/Archive/${PORTVERSION}

MAINTAINER=	lichray@gmail.com
COMMENT=	VYM is a tool to generate and manipulate mind maps

USES=		qmake shebangfix tar:bzip2
SHEBANG_FILES=	scripts/makedist-vym scripts/vivym
USE_QT4=	uic_build moc_build qt3support_build \
		network xml dbus svg
QMAKE_ARGS=	DATADIR=${DATADIR:C,/vym$,,} \
		DOCDIR=${DOCSDIR}

STRIP_FILES=	bin/vym

DESKTOP_ENTRIES=	"VYM" \
			"Put the things you have got in your mind into a map" \
			"${DATADIR}/icons/vym.png" \
			"vym" \
			"" \
			true

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes
NLS_USE=	QT4=linguist_build

.include <bsd.port.options.mk>

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/INSTALLS += doc/d' ${WRKSRC}/vym.pro
.endif

pre-configure:
.if ${PORT_OPTIONS:MNLS}
	${LRELEASE} ${WRKSRC}/vym.pro
.endif

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}
.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${STAGEDIR}${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/lang/*.qm ${STAGEDIR}${DATADIR}/lang/
.endif

.include <bsd.port.mk>
