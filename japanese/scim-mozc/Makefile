# New ports collection makefile for:	scim-mozc
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	scim-mozc
PORTVERSION=	1.3.911.102
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://mozc.googlecode.com/files/
DISTNAME=	mozc-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Mozc engine for SCIM

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/grep:${PORTSDIR}/textproc/gnugrep \
		gyp:${PORTSDIR}/devel/py-gyp-devel \
		scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtest.0:${PORTSDIR}/devel/googletest \
		protobuf.7:${PORTSDIR}/devel/protobuf \
		zinnia.0:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_tool:${PORTSDIR}/japanese/mozc-tool \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify \
		scim:${PORTSDIR}/textproc/scim \
		xdg-open:${PORTSDIR}/devel/xdg-utils

USE_ICONV=	yes
USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=		Does not compile on FreeBSD 7.X
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile: segfault
.endif

# workaround for a gcc4.2.1's namespace bug
.if (${OSVERSION} < 1000000 && ${OSVERSION} > 9000000) || ${OSVERSION} < 802503
BUILD_DEPENDS+=	gcc42:${PORTSDIR}/lang/gcc42
CC=		gcc42
CXX=		g++42
.endif

.if defined(WITH_DEBUG_CODE)
BUILD_MODE=	Debug
.else
BUILD_MODE=	Release
.endif

LOCALBASE_REPLACE_FILES= \
		${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
		${WRKSRC}/base/util.cc \
		${WRKSRC}/base/process.cc \
		${WRKSRC}/unix/scim/scim.gyp \
		${WRKSRC}/unix/scim/scim_mozc.cc \
		${WRKSRC}/handwriting/zinnia_handwriting.cc

post-patch:
	@for FILE in ${LOCALBASE_REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}/; \
		export BUILD_COMMAND=${GMAKE}; \
		export CC=${CC}; export CFLAGS="${CFLAGS}"; \
		export CXX=${CXX}; export CXXFLAGS="${CXXFLAGS}"; \
		export LDFLAGS="-L${LOCALBASE}/lib"; \
		${PYTHON_CMD} build_mozc.py gyp --gypdir=${LOCALBASE}/bin; \
		${PYTHON_CMD} build_mozc.py build_tools \
			-c ${BUILD_MODE}; \
		${PYTHON_CMD} build_mozc.py build \
			-c ${BUILD_MODE} \
			unix/scim/scim.gyp:scim_mozc \
			unix/scim/scim.gyp:scim_mozc_setup

do-install:
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out_linux/${BUILD_MODE}/lib.target/libscim_mozc.so \
		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/mozc.so
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out_linux/${BUILD_MODE}/lib.target/libscim_mozc_setup.so \
		${LOCALBASE}/lib/scim-1.0/1.4.0/SetupUI/mozc_setup.so
	@${MKDIR} ${LOCALBASE}/share/scim-mozc/icons
	@${INSTALL} -o 0 -g 0 -m 444 \
	        ${WRKSRC}/data/images/unix/ui-alpha_full.png \
	        ${LOCALBASE}/share/scim-mozc/icons/scim-mozc-alpha_full.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-alpha_half.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc-alpha_half.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-dictionary.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc-dictionary.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-direct.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc-direct.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-hiragana.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc-hiragana.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-katakana_full.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc-katakana_full.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-katakana_half.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc-katakana_half.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-properties.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc-properties.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ui-tool.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc-tool.png
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${LOCALBASE}/share/scim-mozc/icons/scim-mozc.png

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.post.mk>
