PORTNAME=	alire
DISTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/alire-project/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	alr-${DISTVERSION}-full-sources

MAINTAINER=	agh@riseup.net
COMMENT=	Ada LIbrary REpository (ALIRE) management tool, alr
WWW=		https://alire.ada.dev/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	segfault: raised STORAGE_ERROR : s-intman.adb:136 explicit raise

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild

USES=		ada:12,run desktop-file-utils zip
USE_GCC=	yes:build

_GPR_ARGS=	-j${MAKE_JOBS_NUMBER} -p -XALIRE_OS=freebsd

WRKSRC=		${WRKDIR}/alr-${DISTVERSION}

OPTIONS_DEFINE=	DEBUG DOCS
OPTIONS_SUB=	yes

DOCS_DESC=	Install Design and Development documentation

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDEBUG)
_GPR_ARGS+=	-XALIRE_BUILD_MODE=release
.else
WITH_DEBUG=	yes
.endif

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} gprbuild ${_GPR_ARGS} -P alr_env)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/alr \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/scripts/alr-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/resources/alr.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/resources/alr.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
