# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	readline
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	devel scheme
MASTER_SITES=	http://practical-scheme.net/vault/
PKGNAMEPREFIX=	gauche-
DIST_SUBDIR=	gauche

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Pure gauche/scheme implementation of the Readline library

LICENSE=	PD

RUN_DEPENDS=	gosh:lang/gauche
BUILD_DEPENDS=	gauche-config:lang/gauche

USES=		tar:tgz

GAUCHE_LIBDIR=	${:!gauche-config --sitelibdir!:S,^${PREFIX}/,,}
PLIST_SUB+=	GAUCHE_LIBDIR=${GAUCHE_LIBDIR}

DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
PORTDOCS=	AUTHORS BUGS README

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GAUCHE_LIBDIR}/readline
	${INSTALL_DATA} ${WRKSRC}/readline.scm \
		${STAGEDIR}${PREFIX}/${GAUCHE_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/readline/*.scm \
		${STAGEDIR}${PREFIX}/${GAUCHE_LIBDIR}/readline

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
