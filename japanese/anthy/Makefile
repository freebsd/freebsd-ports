# New ports collection makefile for:   anthy
# Date created:        26 February 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anthy
PORTVERSION=	4300b
CATEGORIES=	japanese
MASTER_SITES=	http://downloads.sourceforge.jp/anthy/5332/:anthy
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:anthy
DIST_SUBDIR=	anthy

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Another kana-kanji conversion system

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

ELISPDIR=	share/emacs/site-lisp
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
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el ${PREFIX}/${ELISPDIR}

.include <bsd.port.mk>
