# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdesdk
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Development Kit

LIB_DEPENDS=	svn_client-1.0:${PORTSDIR}/devel/subversion \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		hunspell-1.3.0:${PORTSDIR}/textproc/hunspell \
		qca.2:${PORTSDIR}/devel/qca
BUILD_DEPENDS=	${LOCALBASE}/include/ltdl.h:${PORTSDIR}/devel/libltdl
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

LATEST_LINK=	${PORTNAME}4

CONFLICTS=	kdeutils-4.5.[0-5]

USE_XZ=		yes
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdehier kdelibs kdeprefix libkonq pimlibs sharedmime \
		akonadi automoc4 qimageblitz_build strigi
USES=		cmake:outsource perl5 gmake
USE_QT4=	corelib dbus declarative designer gui qt3support \
		script scripttools sql xml \
		qmake_build moc_build rcc_build uic_build uic3_build
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

MAN1=	adddebug.1 \
	cervisia.1 \
	cheatmake.1 \
	create_cvsignore.1 \
	create_makefile.1 \
	create_makefiles.1 \
	cvscheck.1 \
	cvslastchange.1 \
	cvslastlog.1 \
	cvsrevertlast.1 \
	cxxmetric.1 \
	extend_dmalloc.1 \
	extractrc.1 \
	fixincludes.1 \
	po2xml.1 \
	pruneemptydirs.1 \
	qtdoc.1 \
	reportview.1 \
	split2po.1 \
	swappo.1 \
	transxx.1 \
	xml2pot.1 \
	zonetab2pot.py.1

OPTIONS_DEFINE=	ANTLR KATE KATE_PATE
OPTIONS_DEFAULT=	KATE

ANTLR_DESC=	Support for po2xml and swappo tools
KATE_DESC=	Install Kate advanced text editor
KATE_PATE_DESC=	Support for Python plugins in Kate

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANTLR}
BUILD_DEPENDS+=	antlr:${PORTSDIR}/devel/antlr
RUN_DEPENDS+=	antlr:${PORTSDIR}/devel/antlr
PLIST_SUB+=	ANTLR=""
.else
CMAKE_ARGS+=	-DWITH_Antlr2:BOOL=off
PLIST_SUB+=	ANTLR="@comment "
.endif

.if ${PORT_OPTIONS:MKATE}
USE_KDE4+=	kate_run
.endif

.if ${PORT_OPTIONS:MKATE_PATE}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/pateplugin.so:${PORTSDIR}/editors/kate-plugin-pate
.endif

post-patch:
	${FIND} ${WRKSRC}/scripts -type f | \
		${XARGS} ${REINPLACE_CMD} -Ee 's,/usr/bin/(perl|python|ruby|svn),${LOCALBASE}/bin/\1,g'
	# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/okteta/mimetypes/CMakeLists.txt

.include <bsd.port.mk>
