# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	readline
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel scheme
MASTER_SITES=	http://practical-scheme.net/vault/
PKGNAMEPREFIX=	gauche-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	gauche

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Pure gauche/scheme implementation of the Readline library

RUN_DEPENDS=	gosh:lang/gauche
BUILD_DEPENDS=	gauche-config:lang/gauche

GAUCHE_LIBDIR=	share/gauche/site/lib
GAUCHE_FILES=	readline/history.scm readline/keymap.scm readline/term-util.scm

PLIST_SUB+=	GAUCHE_LIBDIR=${GAUCHE_LIBDIR}

do-install:
.if !exists(${STAGEDIR}${PREFIX}/${GAUCHE_LIBDIR}/readline)
	${MKDIR} ${STAGEDIR}${PREFIX}/${GAUCHE_LIBDIR}/readline
.endif
	${INSTALL_DATA} ${WRKSRC}/readline.scm ${STAGEDIR}${PREFIX}/${GAUCHE_LIBDIR}
.	for f in ${GAUCHE_FILES}
		${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${GAUCHE_LIBDIR}/readline
.	endfor

.include <bsd.port.mk>
