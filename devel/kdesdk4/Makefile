# New ports collection Makefile for:	kdesdk
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdesdk
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Development Kit

LIB_DEPENDS=	svn_client-1.0:${PORTSDIR}/devel/subversion \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		hunspell-1.3.0:${PORTSDIR}/textproc/hunspell \
		searchclient.0:${PORTSDIR}/deskutils/strigi \
		qca.2:${PORTSDIR}/devel/qca

BUILD_DEPENDS=	${LOCALBASE}/include/ltdl.h:${PORTSDIR}/devel/libltdl \
		${LOCALBASE}/include/qimageblitz/qimageblitz.h:${PORTSDIR}/x11/qimageblitz

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

LATEST_LINK=	${PORTNAME}4

CONFLICTS=	kdeutils-4.5.[0-5]

USE_BZIP2=	yes
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier \
		automoc4 akonadi baseapps sharedmime
KDE4_BUILDENV=	yes
USE_PERL5=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus designer gui qt3support \
		script scripttools sql svg xml \
		qmake_build moc_build rcc_build uic_build uic3_build
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
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

OPTIONS=	ANTLR "Support for po2xml and swappo tools" off \
		KATE "Install Kate advanced text editor" on

.include <bsd.port.options.mk>

.ifdef(WITH_ANTLR)
BUILD_DEPENDS+=	antlr:${PORTSDIR}/devel/antlr
RUN_DEPENDS+=	antlr:${PORTSDIR}/devel/antlr
PLIST_SUB+=	ANTLR=""
.else
CMAKE_ARGS+=	-DWITH_Antlr2:BOOL=off
PLIST_SUB+=	ANTLR="@comment "
.endif

.ifndef(WITHOUT_KATE)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kate:${PORTSDIR}/editors/kate
.endif

post-patch:
	# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/okteta/mimetypes/CMakeLists.txt

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
