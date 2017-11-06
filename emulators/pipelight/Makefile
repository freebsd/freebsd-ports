# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pipelight
PORTVERSION=	0.2.8.2
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/mmueller2012/pipelight/get/ \
		http://repos.fds-team.de/pluginloader/v${DISTVERSION}/:plg
DISTNAME=	v${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} pluginloader.tar.gz:plg pluginloader.tar.gz.sig:plg
DIST_SUBDIR=	pipelight
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for using windows plugins in web browsers

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/gpg2:security/gnupg \
		${LOCALBASE}/bin/bash:shells/bash
LIB_DEPENDS=	libxml2.so:textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/wget:ftp/wget \
		${LOCALBASE}/bin/zenity:x11/zenity \
		${LOCALBASE}/bin/cabextract:archivers/cabextract \
		${LOCALBASE}/bin/flock:sysutils/flock \
		${LOCALBASE}/bin/gpg2:security/gnupg

WRKSRC=		${WRKDIR}/mmueller2012-pipelight-792e7a4885a6
USES=		compiler:c++11-lib gmake localbase:ldflags shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--verbose --wine-path=${LOCALBASE}/bin/wine --win32-prebuilt \
		--win64-prebuilt --moz-plugin-path=${LOCALBASE}/lib/browser_plugins \
		--cxx=${CXX} --bash-interp=${LOCALBASE}/bin/bash \
		--gpg-exec=${LOCALBASE}/bin/gpg2
SHEBANG_FILES=	configure \
		share/install-dependency
USE_XORG=	x11
MAKE_JOBS_UNSAFE=yes
USE_LDCONFIG=	yes

SUB_FILES=	pipelight-mkufs

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	${LOCALBASE}/bin/wine:emulators/wine-staging
RUN_DEPENDS+=	${LOCALBASE}/bin/wine:emulators/wine-staging
.elif ${ARCH} == "amd64"
BUILD_DEPENDS+=	${LOCALBASE}/bin/wine:emulators/i386-wine-staging
RUN_DEPENDS+=	${LOCALBASE}/bin/wine:emulators/i386-wine-staging
.endif

pre-configure:
	@${LN} -s ${DISTDIR}/${DIST_SUBDIR}/pluginloader.tar.gz \
		${WRKSRC}/pluginloader-v${DISTVERSION}.tar.gz
	@${LN} -s ${DISTDIR}/${DIST_SUBDIR}/pluginloader.tar.gz.sig \
		${WRKSRC}/pluginloader-v${DISTVERSION}.tar.gz.sig
	@${MKDIR} ${WRKDIR}/.gnupg

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pipelight-mkufs ${STAGEDIR}${PREFIX}/bin/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pipelight/libpipelight.so

.include <bsd.port.post.mk>
