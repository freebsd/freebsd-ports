# Created by: Stefan Esser <se@StefanEsser.FreeBSD.org>
# $FreeBSD$

PORTNAME=	playonbsd
PORTVERSION=	4.2.10
PORTREVISION=	4
CATEGORIES=	emulators games

MAINTAINER=	se@FreeBSD.org
COMMENT=	Easily install and run Windows software for use with Wine

LICENSE=	GPLv3

RUN_DEPENDS=	7z:archivers/p7zip \
		bash:shells/bash \
		glxinfo:graphics/mesa-demos \
		gpg:security/gnupg \
		gsed:textproc/gsed \
		sudo:security/sudo \
		xdg-open:devel/xdg-utils \
		xterm:x11/xterm \
		cabextract:archivers/cabextract \
		wget:ftp/wget \
		icotool:graphics/icoutils

OPTIONS_DEFINE=	GECKO MONO
OPTIONS_DEFAULT=	GECKO MONO
GECKO_DESC=	Wine-gecko HTML rendering support
MONO_RUN_DEPENDS=	wine-mono>=4.5.6:emulators/wine-mono
GECKO_RUN_DEPENDS=	wine-gecko>=2.21:emulators/wine-gecko

ONLY_FOR_ARCHS=	amd64 i386

USES=		python:2.7,run perl5
USE_WX=		3.0
WX_COMPS=	python:run

USE_GITHUB=	yes
GH_ACCOUNT=	PlayOnLinux
GH_PROJECT=	POL-POM-4

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
RUN_DEPENDS+=	wine:emulators/i386-wine
.else
RUN_DEPENDS+=	wine:emulators/wine
.endif

NO_BUILD=	true
SUB_FILES=	playonbsd.sh

post-patch:
		@${REINPLACE_CMD} -e 's:/usr/local/:${LOCALBASE}/:' ${WRKSRC}/lib/wine.lib

do-install:
.for d in bash python
		cd ${WRKSRC} && ${COPYTREE_BIN} ${d} ${STAGEDIR}${PREFIX}/lib/playonbsd/ "! -name *\.orig ! -name *\.bak"
.endfor
.for d in etc lang lib plugins resources
		cd ${WRKSRC} && ${COPYTREE_BIN} ${d} ${STAGEDIR}${PREFIX}/lib/playonbsd/ "! -name *\.orig ! -name *\.bak"
.endfor
		@${REINPLACE_CMD} -e 's:linux:bsd:g;s:linux:BSD:ig' ${WRKSRC}/doc/playonlinux.1
		${INSTALL_MAN} ${WRKSRC}/doc/playonlinux.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/playonbsd.1
		${INSTALL_SCRIPT} ${WRKDIR}/playonbsd.sh ${STAGEDIR}${PREFIX}/bin/playonbsd
		${INSTALL_SCRIPT} ${WRKSRC}/playonfreebsd ${STAGEDIR}${PREFIX}/lib/playonbsd/playonfreebsd

.include <bsd.port.post.mk>
