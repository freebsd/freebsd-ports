# New ports collection makefile for:	qdevelop
# Date created:				4 Jul 2007
# Whom:					Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	qdevelop
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	http://biord-software.org/downloads/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A development environment entirely dedicated to Qt4

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

USE_QT4=	gui sql network xml designer sql-sqlite3_run \
		qmake_build moc_build uic_build rcc_build
MAKE_JOBS_SAFE=	yes

QMAKE_ARGS=	-recursive ${QMAKE_PRO}
QMAKE_PRO=	QDevelop.pro
STRIP_FILES=	bin/${PORTNAME}

QT_LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

DESKTOP_ENTRIES=	"QDevelop" \
			"Qt4 development environment" \
			"${PREFIX}/share/pixmaps/qdevelop.png" \
			"qdevelop" \
			"Qt;KDE;Development;" \
			"false"

OPTIONS_DEFINE=	TOOLS
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

do-configure:
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC} && ${QT_LRELEASE} ${QMAKE_PRO}
.endif
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}
	${INSTALL_DATA} ${WRKSRC}/resources/images/logo.png ${PREFIX}/share/pixmaps/qdevelop.png
.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/resources/translations/ && ${COPYTREE_SHARE} '*.qm' ${DATADIR}/translations
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ChangeLog.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
