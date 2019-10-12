# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	encryptpad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0.4
PORTREVISION=	8
CATEGORIES=	editors security

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Minimalist secure text editor and binary encryptor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libbotan-2.so:security/botan2

USES=		compiler:c++11-lang desktop-file-utils gl gmake pkgconfig qt:5 \
		shared-mime-info shebangfix
USE_GL=		gl
USE_QT=		core gui widgets buildtools_build qmake_build
SHEBANG_FILES=	deps/libencryptmsg/configure

USE_GITHUB=	yes
GH_ACCOUNT=	evpo
GH_PROJECT=	EncryptPad

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.pre.mk>

post-patch:
.if ${CHOSEN_COMPILER_TYPE} == gcc
	${REINPLACE_CMD} -e 's/freebsd-clang/freebsd-g++/' \
		${WRKSRC}/build/Makefile.qt_ui
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} MAKE=${MAKE_CMD} \
		./configure.sh --all --use-system-libs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/encryptpad.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/encryptpad.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages
.for sz in 16 32 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${INSTALL_DATA} ${WRKSRC}/images/icns.iconset/icon_${sz}x${sz}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/encryptpad.png
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.post.mk>
