# New ports collection makefile for:	apel for emacs
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	apel
PORTVERSION=	${APEL_VER}
PORTREVISION=	6
CATEGORIES=	editors elisp
MASTER_SITES=	http://kanji.zinbun.kyoto-u.ac.jp/~tomo/lemi/dist/apel/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	A Portable Emacs Library for emacs

# distfile version
APEL_VER=	10.8
# apel lispdir
APEL_LISPDIR?=			${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
APEL_VERSION_SPECIFIC_LISPDIR?=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}

# emacs port setup
USE_EMACS=	yes

DESCR=		${PKGDIR}/pkg-descr

# target name for make build
ALL_TARGET?=	elc
# environments
MAKE_ARGS+=	PREFIX="${LOCALBASE}" \
		LISPDIR="${APEL_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${APEL_VERSION_SPECIFIC_LISPDIR}"

.include <bsd.port.pre.mk>

.if ${EMACS_VER:C/\..*//} >= 23
PLIST_SUB+=	EMACS23="" NOEMACS23="@comment "
.else
PLIST_SUB+=	EMACS23="@comment " NOEMACS23=""
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog README.* ; do \
	    ${INSTALL_DATA} $${i} ${DOCSDIR} ; \
	done)
.endif

.include <bsd.port.post.mk>
