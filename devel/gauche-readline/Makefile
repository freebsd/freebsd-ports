# New ports collection makefile for:	Gauche Readline
# Date created:		15 Jan 2004
# Whom:			Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	readline
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel scheme
MASTER_SITES=	http://www.shiro.dreamhost.com/scheme/vault/
PKGNAMEPREFIX=	gauche-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	gauche

MAINTAINER=	erik@smluc.org
COMMENT=	A pure gauche/scheme implementation of the Readline library

RUN_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
BUILD_DEPENDS=	gauche-config:${PORTSDIR}/lang/gauche

BROKEN=		Changes permissions on installed file

GAUCHE_LIBDIR=	share/gauche/site/lib
PLIST_SUB+=	GAUCHE_LIBDIR=${GAUCHE_LIBDIR}

# XXX: exists untill it will be committed to bsd.port.mk
COPYTREE_SHARE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
		2>&1) && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$1 && \
		${FIND} $$1/ -type d -exec ${CHMOD} 755 {} \; && \
		${FIND} $$1/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;' --

do-install:
.if !exists(${PREFIX}/share/gauche/site/lib)
	${MKDIR} ${PREFIX}/share/gauche/site/lib
.endif
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "readline.scm readline" \
		${PREFIX}/share/gauche/site/lib)

.include <bsd.port.mk>
