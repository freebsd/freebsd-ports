# New ports collection makefile for:   anthy
# Date created:        26 February 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anthy
PORTVERSION=	5100
CATEGORIES=	japanese
MASTER_SITES=	http://downloads.sourceforge.jp/anthy/8433/:anthy
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:anthy
DIST_SUBDIR=	anthy

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Another kana-kanji conversion system

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

DOCSDIR=	share/doc/ja/anthy
ELISPDIR=	share/emacs/site-lisp/anthy
PLIST_SUB=	ELISPDIR=${ELISPDIR}

.if defined(WITH_2CHDIC)
MASTER_SITES+=	http://omaemona.sourceforge.net/packages/Zisyo/:2chdic
DISTFILES+=	2ch.t:2chdic
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-mkanthydic:Makefile.in
.endif

.if defined(WITH_2CHDIC)
post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/2ch.t ${WRKSRC}/mkanthydic
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| install-lispLISP||g' ${WRKSRC}/src-util/Makefile.in

post-install:
	${MKDIR} ${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el ${PREFIX}/${ELISPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${PREFIX}/${DOCSDIR}
.endif

.include <bsd.port.mk>
