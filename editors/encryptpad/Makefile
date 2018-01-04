# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	encryptpad
PORTVERSION=	0.3.2.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	editors security

MAINTAINER=	dg@syrec.org
COMMENT=	Minimalist secure text editor and binary encryptor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libbotan-1.10.so:security/botan110

USE_GITHUB=	yes
GH_ACCOUNT=	evpo
GH_PROJECT=	EncryptPad

USES=		desktop-file-utils gmake pkgconfig shared-mime-info
USE_QT5=	core gui widgets qmake_build buildtools_build
USE_GL=		gl

PORTDOCS=	CHANGES.* README.* docs

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && ${SETENV} MAKE=${MAKE_CMD} PATH=${QT_BINDIR}:${PATH} \
		./configure.sh --all --use-system-libs)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/encryptpad.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/encryptpad.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages
.for sz in 16 32 128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${INSTALL_DATA} ${WRKSRC}/images/icns.iconset/icon_${sz}x${sz}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/encryptpad.png
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
