PORTNAME=	encryptpad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0.4
PORTREVISION=	1
CATEGORIES=	editors security

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Minimalist secure text editor and binary encryptor
WWW=		https://evpo.net/encryptpad/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libbotan-3.so:security/botan3

USES=		compiler:c++11-lang desktop-file-utils gl gmake pkgconfig \
		python:build qt:6 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	evpo
GH_PROJECT=	EncryptPad
GH_TAGNAME=	a0360d132b1367a9ba5328253a1c4d402266b4bd # qt6 branch (plus botan3 support) 20250623
USE_GL=		opengl
USE_QT=		base svg

BINARY_ALIAS=	python3=${PYTHON_CMD} qmake=${QMAKE}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
CONFIGURE_ARGS=	--cpu="ppc64"
.elif ${ARCH} == powerpc64le
CONFIGURE_ARGS=	--cpu="ppc64le"
.endif

.include <bsd.port.pre.mk>

post-patch:
.if ${CHOSEN_COMPILER_TYPE} == gcc
	${REINPLACE_CMD} -e 's/freebsd-clang/freebsd-g++/' \
		${WRKSRC}/build/Makefile.qt_ui
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./configure.py ${CONFIGURE_ARGS}

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
