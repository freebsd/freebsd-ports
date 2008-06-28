# New ports collection makefile for:	qdevelop
# Date created:				4 Jul 2007
# Whom:					Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	qdevelop
PORTVERSION=	0.25.2
CATEGORIES=	devel kde
MASTER_SITES=	http://qdevelop.free.fr/download/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	A development environment entirely dedicated to Qt4

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		qt4-sqlite-plugin>=0:${PORTSDIR}/databases/qt4-sqlite3-plugin

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc uic rcc sql network xml gui corelib assistant linguist designer
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

DESKTOP_ENTRIES=	"QDevelop" \
			"Qt4 development environment" \
			"qdevelop" \
			"qdevelop" \
			"Qt;KDE;Development;" \
			"false"

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
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

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qdevelop ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/resources/images/logo.png ${PREFIX}/share/pixmaps/qdevelop.png
.if !defined(WITHOUT_NLS)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/resources/translations/ && ${COPYTREE_SHARE} '*.qm' ${DATADIR}/translations)
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ChangeLog.txt README.txt README.cmake copying
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
