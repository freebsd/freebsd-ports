# Created by: Yinghong.Liu <liu_yinghong@yahoo.com.cn>
# $FreeBSD$

PORTNAME=	qdevelop
PORTVERSION=	0.28
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	http://biord-software.org/downloads/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Development environment entirely dedicated to Qt4

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

USE_QT4=	gui sql network xml designer sql-sqlite3_run \
		moc_build uic_build rcc_build
USES=		qmake

QMAKE_PRO=	QDevelop.pro
STRIP_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES=	"QDevelop" \
			"Qt4 development environment" \
			"${PREFIX}/share/pixmaps/qdevelop.png" \
			"qdevelop" \
			"Development;IDE;Qt;" \
			true

OPTIONS_DEFINE=	TOOLS DOCS NLS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
TOOLS_DESC=	Install Qt4 dev. tools (qmake, moc, etc.)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MTOOLS}
USE_QT4+=	assistant_run linguist_run \
		qmake_run moc_run uic_run rcc_run
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|\"qmake\"|\"qmake-qt4\"|g" \
		-e "s|\"linguist\"|\"linguist-qt4\"|g" \
		-e "s|\"lupdate\"|\"lupdate-qt4\"|g" \
		-e "s|\"lrelease\"|\"lrelease-qt4\"|g" \
		-e "s|\"designer\"|\"designer-qt4\"|g" \
		-e "s|\"assistant\"|\"assistant-qt4\"|g" \
		-e "s|\"/usr/bin/make\"|\"${LOCALBASE}/bin/gmake\"|g" \
		-e "s|\"/usr/bin/ctags\"|\"${LOCALBASE}/bin/exctags\"|g" \
		${WRKSRC}/src/toolscontrolimpl.cpp
	${REINPLACE_CMD} -e "/target.path/s|/usr/bin/|${PREFIX}/bin|g" \
		${WRKSRC}/${QMAKE_PRO}
	${REINPLACE_CMD} -e "s,lib/qdevelop/translations,${DATADIR_REL}/translations,g" \
		${WRKSRC}/src/main.cpp \
		${WRKSRC}/plugins/tools-regexp-planner/replugin.cpp \
		${WRKSRC}/plugins/formatting-astyle/astyleplugin.cpp

post-configure:
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC} && ${LRELEASE} ${QMAKE_PRO}
.endif

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}
	${INSTALL_DATA} ${WRKSRC}/resources/images/logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/qdevelop.png
.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/resources/translations/*.qm ${STAGEDIR}${DATADIR}/translations
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.txt ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
