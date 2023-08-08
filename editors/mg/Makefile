PORTNAME=	mg
DISTVERSION=	20230501
PORTEPOCH=	1
CATEGORIES=	editors

MAINTAINER=	cdr.nil@gmail.com
COMMENT=	Small, fast Emacs-like editor
WWW=		https://github.com/hboetes/mg

LICENSE=	PD

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	hboetes
STAGEOWN=	${USER}
STAGEGRP!=	id -gn
MAKE_ARGS+=	BINOWN=${STAGEOWN} BINGRP=${STAGEGRP} MANOWN=${STAGEOWN} \
		MANGRP=${STAGEGRP} BINDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/man/man NCURSESLIB=${NCURSESLIB} \
		NCURSESINC=${NCURSESINC}
FLAVORS=	dynamic static
FLAVOR?=	${FLAVORS:[1]}
static_PKGNAMESUFFIX=	-static
.if ${FLAVOR} == static
COMMENT+=	(rescue(8) version)
MAKE_ARGS+= 	NO_SHARED=yes
PLIST_FILES=	/rescue/mg
.else
PLIST_FILES=	bin/mg \
		man/man1/mg.1.gz
PORTDOCS=	README README.md tutorial
OPTIONS_DEFINE=	DOCS
.endif

.if ${FLAVOR} == static
do-install:
	@${MKDIR} ${STAGEDIR}/rescue
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${STAGEDIR}/rescue
.else
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
