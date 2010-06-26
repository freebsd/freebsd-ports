# New ports collection makefile for:	mozc-tool
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mozc-tool
PORTVERSION=	0.11.383.102
CATEGORIES=	japanese
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
DISTNAME=	mozc-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	daichi@freebsd.org
COMMENT=	Mozc tool for IBus, SCIM and others

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
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

REPLACE_FILES=	${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
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
		${SED} -i .bak -e "s/sed/gsed/g" Makefile; \
		${PYTHON_CMD} build_mozc.py build_tools -c Release; \
		${PYTHON_CMD} build_mozc.py build -c Release \
			gui/gui.gyp:mozc_tool

do-install:
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out/Release/mozc_tool \
		${LOCALBASE}/bin/mozc_tool

.include <bsd.port.post.mk>
