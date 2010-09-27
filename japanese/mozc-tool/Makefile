# New ports collection makefile for:	mozc-tool
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mozc-tool
PORTVERSION=	0.13.481.102
CATEGORIES=	japanese
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
DISTNAME=	mozc-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	daichi@freebsd.org
COMMENT=	Mozc tool for IBus, SCIM and others

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/grep:${PORTSDIR}/textproc/gnugrep \
		gyp:${PORTSDIR}/devel/py-gyp-devel
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtest.0:${PORTSDIR}/devel/googletest \
		protobuf.6:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_GMAKE=	yes
USE_ICONV=	yes
USE_PYTHON=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus qmake_build moc_build uic_build rcc_build

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=	Does not compile on FreeBSD 7.X
.endif

.if defined(WITH_DEBUG_CODE)
BUILD_MODE=Debug
.else
BUILD_MODE=Release
.endif

REPLACE_FILES=	${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
		${WRKSRC}/base/util.cc \
		${WRKSRC}/base/process.cc \
		${WRKSRC}/gui/about_dialog/about_dialog.cc \
		${WRKSRC}/gui/about_dialog/version_image_widget.cc

post-patch:
	@for FILE in ${REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}/; \
		${PYTHON_CMD} build_mozc.py gyp --gypdir=${LOCALBASE}/bin; \
		${PYTHON_CMD} build_mozc.py build_tools -c ${BUILD_MODE}; \
		${PYTHON_CMD} build_mozc.py build -c ${BUILD_MODE} \
			gui/gui.gyp:mozc_tool

do-install:
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_tool \
		${LOCALBASE}/bin/mozc_tool
	@${MKDIR} ${LOCALBASE}/share/mozc-tool/icons
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${LOCALBASE}/share/mozc-tool/icons/product_logo.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${LOCALBASE}/share/mozc-tool/icons/update_uptodate.png

.include <bsd.port.post.mk>
