# New ports collection makefile for:	scim-mozc
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	scim-mozc
PORTVERSION=	0.11.383.102
CATEGORIES=	japanese
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
DISTNAME=	mozc-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	daichi@freebsd.org
COMMENT=	Mozc engine for SCIM

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		gyp:${PORTSDIR}/devel/py-gyp-devel \
		scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtest.0:${PORTSDIR}/devel/googletest \
		protobuf.6:${PORTSDIR}/devel/protobuf
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
BROKEN=	Does not compile on FreeBSD 7.X
.endif

REPLACE_FILES=	${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
		${WRKSRC}/base/util.cc \
		${WRKSRC}/base/process.cc \
		${WRKSRC}/unix/scim/scim.gyp \
		${WRKSRC}/unix/scim/scim_mozc.cc

post-patch:
	@for FILE in ${REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}/; \
		${PYTHON_CMD} build_mozc.py gyp --gypdir=${LOCALBASE}/bin; \
		${SED} -i .bak -e "s/sed/gsed/g" Makefile; \
		${PYTHON_CMD} build_mozc.py build_tools -c Release; \
		${PYTHON_CMD} build_mozc.py build -c Release \
			unix/scim/scim.gyp:scim_mozc \
			unix/scim/scim.gyp:scim_mozc_setup

do-install:
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out/Release/lib.target/libscim_mozc.so \
		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/mozc.so
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out/Release/lib.target/libscim_mozc_setup.so \
		${LOCALBASE}/lib/scim-1.0/1.4.0/SetupUI/mozc_setup.so

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.post.mk>
