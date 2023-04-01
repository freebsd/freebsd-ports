PORTNAME=	git-cinnabar
DISTVERSION=	0.5.11
PORTREVISION=	6
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Git remote helper to interact with Mercurial repositories
WWW=		https://github.com/glandium/git-cinnabar

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	glandium
GH_TUPLE=	git:git:v2.38.1:git/git-core

USES=		gmake iconv python:3.6+,run shebangfix
TARGET_ORDER_OVERRIDE=	510:fix-shebang # after do-patch
SHEBANG_FILES=	${PORTNAME} git-remote-hg
ALL_TARGET=	${PORTNAME}-helper
MAKE_ENV=	V=1
MAKE_ARGS=	SUBMODULE_STATUS=dummy NEEDS_LIBICONV=${ICONV_LIB} \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CFLAGS+=	-ffunction-sections -fdata-sections
LDFLAGS+=	-Wl,--gc-sections
DATADIR=	${PREFIX}/libexec/git-core
PORTDATA=	*
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${WRKSRC}/git-remote-hg \
		${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/git-core/${PORTNAME}-helper \
		${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTNAME:S/git-//}" \
		${STAGEDIR}${DATADIR}/pythonlib)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
