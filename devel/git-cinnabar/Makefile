# $FreeBSD$

PORTNAME=	git-cinnabar
DISTVERSION=	0.5.6
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Git remote helper to interact with Mercurial repositories

LICENSE=	GPLv2

BUILD_DEPENDS=	${NONEXISTENT}:devel/git:configure
RUN_DEPENDS=	git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	glandium

USES=		gmake python:3.6+,run shebangfix
TARGET_ORDER_OVERRIDE=	510:fix-shebang # after do-patch
SHEBANG_FILES=	${PORTNAME} git-remote-hg
ALL_TARGET=	${PORTNAME}-helper
MAKE_ENV=	${:!${MAKE} -V MAKE_ENV -C ${.CURDIR:H}/git!}
MAKE_ARGS=	SUBMODULE_STATUS=dummy ${:!${MAKE} -V MAKE_ARGS -C ${.CURDIR:H}/git!}
CFLAGS+=	-ffunction-sections -fdata-sections
LDFLAGS+=	-Wl,--gc-sections
.export		CPPFLAGS CFLAGS CXXFLAGS LDFLAGS # :configure
DATADIR=	${PREFIX}/libexec/git-core
PORTDATA=	*
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-configure:
	@${TAR} cf - -C$$(${MAKE} -V WRKSRC -C ${PORTSDIR}/devel/git) . | \
		${TAR} xof - -C${WRKSRC}/git-core

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
