# New ports collection makefile for:	mozc-el
# Date created:				26 June 2010
# Whom:					TAKANO, Yuji
#
# $FreeBSD$
#

PORTNAME=	mozc-el
PORTVERSION=	1.1.773.102
PORTREVISION=	3
CATEGORIES=	japanese textproc
MASTER_SITES=	http://mozc.googlecode.com/files/
DISTNAME=	mozc-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Mozc for GNU Emacs

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/grep:${PORTSDIR}/textproc/gnugrep \
		gyp:${PORTSDIR}/devel/py-gyp-devel \
		zinnia:${PORTSDIR}/japanese/zinnia
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtest.0:${PORTSDIR}/devel/googletest \
		protobuf.7:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_BZIP2=	yes
USE_EMACS=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PYTHON=	yes

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/mozc.el \
		${EMACS_VERSION_SITE_LISPDIR}/mozc.elc \
		bin/mozc_emacs_helper

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.X
.endif

.if defined(WITH_DEBUG_CODE)
BUILD_MODE=Debug
.else
BUILD_MODE=Release
.endif

.if !defined(NOPORTDOCS)
SUB_FILES=	pkg-message
.endif

REPLACE_FILES=	${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
		${WRKSRC}/base/util.cc \
		${WRKSRC}/base/process.cc \
		${WRKSRC}/gui/about_dialog/about_dialog.cc

post-patch:
	@for FILE in ${REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}/; \
		export BUILD_COMMAND=${GMAKE}; \
		${PYTHON_CMD} build_mozc.py gyp --gypdir=${LOCALBASE}/bin; \
		${PYTHON_CMD} build_mozc.py build_tools \
			-c ${BUILD_MODE}; \
		${PYTHON_CMD} build_mozc.py build \
			-c ${BUILD_MODE} \
			unix/emacs/emacs.gyp:mozc_emacs_helper
	@cd ${WRKSRC}/unix/emacs; \
		${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile mozc.el

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_emacs_helper \
		${LOCALBASE}/bin/mozc_emacs_helper
	@${INSTALL_DATA} \
		${WRKSRC}/unix/emacs/mozc.el \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc.el
	@${INSTALL_DATA} \
		${WRKSRC}/unix/emacs/mozc.elc \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc.elc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
