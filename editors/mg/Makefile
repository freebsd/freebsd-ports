# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	mg
PORTVERSION=	6.8.1
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	https://github.com/ibara/mg/releases/download/mg-${PORTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Small, fast Emacs-like editor

LICENSE=	PD

FLAVORS=	dynamic static
FLAVOR?=	${FLAVORS:[1]}

static_PKGNAMESUFFIX=	-static
.if ${FLAVOR} == static
COMMENT+=		(rescue(8) version)
.endif

USES=		ncurses
HAS_CONFIGURE=	yes
.if ${FLAVOR} == static
CONFIGURE_ARGS=	--enable-static
PLIST_FILES=	/rescue/mg
.else
PLIST_FILES=	bin/mg \
		man/man1/mg.1.gz
PORTDOCS=	README-Mg README.md tutorial

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
