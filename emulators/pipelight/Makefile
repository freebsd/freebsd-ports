# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pipelight
DISTVERSION=	0.2.7.3
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/mmueller2012/pipelight/get/ \
		http://repos.fds-team.de/pluginloader/v${DISTVERSION}/:plg
DISTNAME=	v${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} pluginloader.tar.gz:plg pluginloader.tar.gz.sig:plg
DIST_SUBDIR=	pipelight
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Wrapper for using windows plugins in web browsers

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/gpg2:${PORTSDIR}/security/gnupg \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget \
		${LOCALBASE}/bin/zenity:${PORTSDIR}/x11/zenity \
		${LOCALBASE}/bin/cabextract:${PORTSDIR}/archivers/cabextract \
		${LOCALBASE}/bin/flock:${PORTSDIR}/sysutils/flock \
		${LOCALBASE}/bin/gpg2:${PORTSDIR}/security/gnupg

WRKSRC=		${WRKDIR}/mmueller2012-pipelight-79b1b7ba0032
USE_GCC=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose --wine-path=${LOCALBASE}/bin/wine --win32-prebuilt \
		--win64-prebuilt --moz-plugin-path=${LOCALBASE}/lib/browser_plugins \
		--cxx=${CXX} --bash-interp=${LOCALBASE}/bin/bash
USE_XORG=	x11
USES=		compiler:gcc-c++11-lib gmake shebangfix
MAKE_JOBS_UNSAFE=yes
bash_OLD_CMD=	/usr/bin/env bash
SHEBANG_FILES=	configure \
		share/install-dependency

SUB_FILES=	pipelight-mkufs

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	${LOCALBASE}/bin/wine:${PORTSDIR}/emulators/wine-compholio
RUN_DEPENDS+=	${LOCALBASE}/bin/wine:${PORTSDIR}/emulators/wine-compholio
.elif ${ARCH} == "amd64"
BUILD_DEPENDS+=	${LOCALBASE}/bin/wine:${PORTSDIR}/emulators/i386-wine-compholio
RUN_DEPENDS+=	${LOCALBASE}/bin/wine:${PORTSDIR}/emulators/i386-wine-compholio
.endif

pre-configure:
		${LN} -s ${DISTDIR}/${DIST_SUBDIR}/pluginloader.tar.gz ${WRKSRC}/pluginloader-v${DISTVERSION}.tar.gz
		${LN} -s ${DISTDIR}/${DIST_SUBDIR}/pluginloader.tar.gz.sig ${WRKSRC}/pluginloader-v${DISTVERSION}.tar.gz.sig

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/pipelight-mkufs ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
