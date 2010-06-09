# New ports collection makefile for:	ibus-mozc
# Date created:				22 May 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-mozc
PORTVERSION=	r28
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
#MASTER_SITES=	${MASTER_SITE_LOCAL}
#MASTER_SITE_SUBDIR=	daichi
DISTNAME=	${PORTNAME}-${PORTVERSION}+gyp-r827
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-freebsd-addition-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	daichi@freebsd.org
COMMENT=	Mozc engine for IBus

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	ibus.1:${PORTSDIR}/textproc/ibus \
		curl.6:${PORTSDIR}/ftp/curl \
		protobuf.6:${PORTSDIR}/devel/protobuf \
		gtest.0:${PORTSDIR}/devel/googletest
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

BROKEN=		does not compile

USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_QT_VER=	4

PROJECTHOST=	ibus

ADDITIONNAME=	${PORTNAME}-freebsd-addition-${PORTVERSION}
REPLACE_FILES=	\
		${WRKSRC}/src/build_mozc.py \
		${WRKSRC}/src/gyp/common.gypi \
		${WRKSRC}/src/unix/ibus/mozc.xml \
		${WRKSRC}/src/unix/ibus/path_util.cc \
		${WRKSRC}/src/base/util.cc \
		${WRKSRC}/src/base/process.cc \
		${WRKSRC}/../${ADDITIONNAME}/bin/mozc_server_start \
		${WRKSRC}/../${ADDITIONNAME}/bin/mozc_tool_config \
		${WRKSRC}/../${ADDITIONNAME}/bin/mozc_tool_dictionary

post-patch:
	@for FILE in ${REPLACE_FILES}; do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}/src; \
		${PYTHON_CMD} build_mozc.py gyp; \
		${SED} -i .bak -e "s/sed/gsed/g" Makefile; \
		${PYTHON_CMD} build_mozc.py build_tools -c Release; \
		${PYTHON_CMD} build_mozc.py build -c Release \
			unix/ibus/ibus.gyp:ibus_mozc \
			server/server.gyp:mozc_server \
			gui/gui.gyp:mozc_tool

do-install:
	@${MKDIR} ${LOCALBASE}/share/ibus-mozc/server
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/src/out/Release/mozc_server \
		${LOCALBASE}/share/ibus-mozc/server/mozc_server
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/src/out/Release/mozc_tool \
		${LOCALBASE}/share/ibus-mozc/server/mozc_tool
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/src/out/Release/ibus_mozc \
		${LOCALBASE}/libexec/ibus-engine-mozc
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/src/unix/ibus/mozc.xml \
		${LOCALBASE}/share/ibus/component/mozc.xml
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/../${ADDITIONNAME}/bin/mozc_server_start \
		${LOCALBASE}/bin/mozc_server_start
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/../${ADDITIONNAME}/bin/mozc_server_stop \
		${LOCALBASE}/bin/mozc_server_stop
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/../${ADDITIONNAME}/bin/mozc_server_restart \
		${LOCALBASE}/bin/mozc_server_restart
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/../${ADDITIONNAME}/bin/mozc_tool_config \
		${LOCALBASE}/bin/mozc_tool_config
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/../${ADDITIONNAME}/bin/mozc_tool_dictionary \
		${LOCALBASE}/bin/mozc_tool_dictionary
	@${MKDIR} ${LOCALBASE}/share/ibus-mozc/icons
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/../${ADDITIONNAME}/icons/mozc-temp-icon.png \
		${LOCALBASE}/share/ibus-mozc/icons/product_icon.png

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
