# New ports collection makefile for:	Free Chinese Input Toy for X
# Date created:				26 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fcitx
PORTVERSION=	4.2.0
CATEGORIES=	chinese x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} pinyin.tar.gz table.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lichray@gmail.com
COMMENT=	A simple and fast GBK Chinese XIM server

LICENSE=	GPLv2

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		dbus-1.3:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

MAN1=	createPYMB.1 fcitx-remote.1 fcitx.1 mb2org.1 mb2txt.1 \
	readPYBase.1 readPYMB.1 scel2org.1 txt2mb.1

USE_BZIP2=	yes
USE_GNOME=	pango intltool gnomehack
USE_GETTEXT=	yes
USE_XORG=	x11 xext
USE_LDCONFIG=	yes
USE_CMAKE=	yes
INSTALLS_ICONS=	yes

OPTIONS=	GTK2		"Enable Gtk2 IM module" off \
		GTK3		"Enable Gtk3 IM module" off \
		QT4		"Enable Qt4 IM module" off \
		OPENCC		"Enable OpenCC for Chinese Transform" off \
		TPUNC		"Use traditional quotation marks" off

.include <bsd.port.options.mk>

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
.else
CMAKE_ARGS+=	-DENABLE_GTK2_IM_MODULE=OFF
.endif

.if defined(WITH_GTK3)
USE_GNOME+=	gtk30
CMAKE_ARGS+=	-DENABLE_GTK3_IM_MODULE=ON
.endif

.if defined(WITH_QT4)
USE_QT=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui
CMAKE_ARGS+=	-DENABLE_QT_IM_MODULE=ON
.endif

.if defined(WITH_OPENCC)
LIB_DEPENDS+=	opencc.1:${PORTSDIR}/chinese/opencc
.else
CMAKE_ARGS+=	-DENABLE_OPENCC=OFF
.endif

.if defined(WITH_TPUNC)
EXTRA_PATCHES+=	${FILESDIR}/tpunc-data_punc.mb.zh_CN
.endif

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DENABLE_DEBUG=ON
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/nodocs-doc_CMakeLists.txt
.endif

.if defined(NOPORTDATA)
IGNORE=		code tables are required, undefine NOPORTDATA
.endif

post-patch:
	@${CP} ${_DISTDIR}/pinyin.tar.gz ${WRKSRC}/data
	@${CP} ${_DISTDIR}/table.tar.gz ${WRKSRC}/data/table
.if ${OSVERSION} < 800067
# getline() is GNU extension which FreeBSD only recently adopted
EXTRA_PATCHES+=	${FILESDIR}/getline-src_lib_fcitx-utils_utils.c \
		${FILESDIR}/getline-src_lib_fcitx-utils_utils.h
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
