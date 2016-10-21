# Created by: Yinghong.Liu <liu_yinghong@yahoo.com.cn>
# $FreeBSD$

PORTNAME=	qdevelop
PORTVERSION=	0.28
PORTREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	http://biord-software.org/downloads/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Development environment entirely dedicated to Qt 4

RUN_DEPENDS=	exctags:devel/ctags

USE_QT4=	gui sql network xml designer sql-sqlite3_run \
		moc_build uic_build rcc_build
USES=		qmake

DESKTOP_ENTRIES=	"QDevelop" \
			"Qt 4 development environment" \
			"${PREFIX}/share/pixmaps/qdevelop.png" \
			"qdevelop" \
			"Development;IDE;Qt;" \
			true

OPTIONS_DEFINE=	TOOLS DOCS NLS
OPTIONS_DEFAULT:=	${OPTIONS_DEFINE}
OPTIONS_SUB=	yes
NLS_USE=	QT4=linguisttools_build
TOOLS_DESC=	Install Qt 4 development tools (qmake, moc, etc.)
TOOLS_USE=	${_TOOLS:C|.*|QT4=&_run|}
_TOOLS=		assistant linguisttools moc qmake rcc uic

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
		${WRKSRC}/QDevelop.pro
	${REINPLACE_CMD} -e "s,lib/qdevelop/translations,${DATADIR_REL}/translations,g" \
		${WRKSRC}/src/main.cpp \
		${WRKSRC}/plugins/tools-regexp-planner/replugin.cpp \
		${WRKSRC}/plugins/formatting-astyle/astyleplugin.cpp

post-configure-NLS-on:
	${LRELEASE} ${WRKSRC}/QDevelop.pro

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/images/logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/qdevelop.png

post-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/resources/translations/*.qm ${STAGEDIR}${DATADIR}/translations

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.txt ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
