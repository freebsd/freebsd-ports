# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	encryptpad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0.2
PORTREVISION=	1
CATEGORIES=	editors security

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	55fd37480d.patch:-p1

MAINTAINER=	dg@syrec.org
COMMENT=	Minimalist secure text editor and binary encryptor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libbotan-2.so:security/botan2

USES=		desktop-file-utils gmake pkgconfig shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	evpo
GH_PROJECT=	EncryptPad
USE_QT5=	core gui widgets buildtools_build qmake_build
USE_GL=		gl

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-build:
	@cd ${WRKSRC} && ${SETENV} MAKE=${MAKE_CMD} PATH=${QT_BINDIR}:${PATH} \
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

.include <bsd.port.mk>
