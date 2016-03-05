# Created by: Stefan Esser <se@StefanEsser.FreeBSD.org>
# $FreeBSD$

PORTNAME=	playonbsd
PORTVERSION=	4.2.8
CATEGORIES=	emulators games

MAINTAINER=	se@FreeBSD.org
COMMENT=	Easily install and run Windows software for use with wine

LICENSE=	GPLv3

RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip \
		bash:${PORTSDIR}/shells/bash \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		gpg:${PORTSDIR}/security/gnupg \
		gsed:${PORTSDIR}/textproc/gsed \
		sudo:${PORTSDIR}/security/sudo \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		xterm:${PORTSDIR}/x11/xterm

OPTIONS_DEFINE=	GECKO MONO
OPTIONS_DEFAULT=	GECKO MONO
GECKO_DESC=	Wine-gecko HTML rendering support
MONO_RUN_DEPENDS=	wine-mono-devel>=4.5.6:${PORTSDIR}/emulators/wine-mono-devel
GECKO_RUN_DEPENDS=	wine-gecko>=2.21:${PORTSDIR}/emulators/wine-gecko

ONLY_FOR_ARCHS=	amd64 i386

USES=		python:run
USE_PERL=	yes
USE_WX=		2.8+
WX_COMPS=	python:run

USE_GITHUB=	yes
GH_ACCOUNT=	PlayOnLinux
GH_PROJECT=	POL-POM-4

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
RUN_DEPENDS+=	wine:${PORTSDIR}/emulators/i386-wine-devel
.else
RUN_DEPENDS+=	wine:${PORTSDIR}/emulators/wine
.endif

NO_BUILD=	true
SUB_FILES=	playonbsd.sh

post-patch:
		@${REINPLACE_CMD} -e 's:/usr/local/:${LOCALBASE}/:' ${WRKSRC}/lib/wine.lib

do-install:
		cd ${WRKSRC} && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/lib/playonbsd/ "-perm -0100 ! -name *.orig"
		cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/playonbsd/ "! -perm 0100 ! -name *.orig"
		${INSTALL_SCRIPT} ${WRKDIR}/playonbsd.sh ${STAGEDIR}${PREFIX}/bin/playonbsd

.include <bsd.port.post.mk>
