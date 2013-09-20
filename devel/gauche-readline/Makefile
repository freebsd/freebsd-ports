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
COMMENT=	A pure gauche/scheme implementation of the Readline library

RUN_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
BUILD_DEPENDS=	gauche-config:${PORTSDIR}/lang/gauche

GAUCHE_LIBDIR=	share/gauche/site/lib
GAUCHE_FILES=	readline/history.scm readline/keymap.scm readline/term-util.scm

PLIST_SUB+=	GAUCHE_LIBDIR=${GAUCHE_LIBDIR}

NO_STAGE=	yes
do-install:
.if !exists(${PREFIX}/${GAUCHE_LIBDIR}/readline)
	${MKDIR} ${PREFIX}/${GAUCHE_LIBDIR}/readline
.endif
	${INSTALL_DATA} ${WRKSRC}/readline.scm ${PREFIX}/${GAUCHE_LIBDIR}
.	for f in ${GAUCHE_FILES}
		${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${GAUCHE_LIBDIR}/readline
.	endfor

.include <bsd.port.mk>
