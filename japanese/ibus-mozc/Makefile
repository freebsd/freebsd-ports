# New ports collection makefile for:	ibus-mozc
# Date created:				22 May 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-mozc
PORTVERSION=	0.13.464.102
CATEGORIES=	japanese
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
DISTNAME=	mozc-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	daichi@freebsd.org
COMMENT=	Mozc engine for IBus

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/grep:${PORTSDIR}/textproc/gnugrep \
		gyp:${PORTSDIR}/devel/py-gyp-devel
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtest.0:${PORTSDIR}/devel/googletest \
		ibus.2:${PORTSDIR}/textproc/ibus \
		protobuf.6:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_tool:${PORTSDIR}/japanese/mozc-tool \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify \
		xdg-open:${PORTSDIR}/devel/xdg-utils

PROJECTHOST=	ibus
USE_ICONV=	yes
USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=	Does not compile on FreeBSD 7.X
.endif

REPLACE_FILES=	${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
		${WRKSRC}/unix/ibus/gen_mozc_xml.py \
		${WRKSRC}/unix/ibus/mozc.xml \
		${WRKSRC}/unix/ibus/path_util.cc \
		${WRKSRC}/base/util.cc \
		${WRKSRC}/base/process.cc \

post-patch:
	@for FILE in ${REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}/; \
		${PYTHON_CMD} build_mozc.py gyp --gypdir=${LOCALBASE}/bin; \
		${PYTHON_CMD} build_mozc.py build_tools -c Release; \
		${PYTHON_CMD} build_mozc.py build -c Release \
			unix/ibus/ibus.gyp:ibus_mozc

do-install:
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out_linux/Release/ibus_mozc \
		${LOCALBASE}/libexec/ibus-engine-mozc
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/unix/ibus/mozc.xml \
		${LOCALBASE}/share/ibus/component/mozc.xml
	@${MKDIR} ${LOCALBASE}/share/ibus-mozc/icons
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-alpha_full.png \
		${LOCALBASE}/share/ibus-mozc/icons/alpha_full.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-alpha_half.png \
		${LOCALBASE}/share/ibus-mozc/icons/alpha_half.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-dictionary.png \
		${LOCALBASE}/share/ibus-mozc/icons/dictionary.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-direct.png \
		${LOCALBASE}/share/ibus-mozc/icons/direct.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-hiragana.png \
		${LOCALBASE}/share/ibus-mozc/icons/hiragana.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-katakana_full.png \
		${LOCALBASE}/share/ibus-mozc/icons/katakana_full.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-katakana_half.png \
		${LOCALBASE}/share/ibus-mozc/icons/katakana_half.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${LOCALBASE}/share/ibus-mozc/icons/product_logo.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-properties.png \
		${LOCALBASE}/share/ibus-mozc/icons/properties.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-tool.png \
		${LOCALBASE}/share/ibus-mozc/icons/tool.png

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.post.mk>
