# $FreeBSD$

PORTNAME=	git-cinnabar
DISTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Git remote helper to interact with Mercurial repositories

LICENSE=	GPLv2

BUILD_DEPENDS=	${NONEXISTENT}:devel/git:configure
RUN_DEPENDS=	git:devel/git \
		hg:devel/mercurial

USE_GITHUB=	yes
GH_ACCOUNT=	glandium

USES=		gmake python:2.7,run shebangfix
SHEBANG_LANG=	python2.7
SHEBANG_FILES=	${PORTNAME} git-remote-hg
ALL_TARGET=	${PORTNAME}-helper
.ifnmake describe
MAKE_ENV!=	${MAKE} -V MAKE_ENV -C ${.CURDIR}/../git
MAKE_ARGS!=	${MAKE} -V MAKE_ARGS -C ${.CURDIR}/../git
.endif
MAKE_ENV+=	PYTHON_PATH="${PYTHON_CMD}"
MAKE_ARGS+=	SUBMODULE_STATUS=dummy
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
