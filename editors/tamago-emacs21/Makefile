# New ports collection makefile for:	tamago
# Date created:		6 March 2000
# Whom:			tetsushi NAKAI <nakai@tsl.pe.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	tamago
PORTVERSION=	4.0.6
PORTREVISION=	1
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.m17n.org/pub/tamago/ \
		ftp://ftp.kddlabs.co.jp/Japan/m17n.org/tamago/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	kuriyama
PATCHFILES=	tamago-${PORTVERSION}-20011028.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	The Multilingual Input Method - Egg V4

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EMACS_PORT_NAME?=	emacs21

ELISPDIR=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
PLIST_SUB=	ELISPDIR="${EMACS_LIBDIR_WITH_VER}/site-lisp"

pre-configure:
	@${REINPLACE_CMD} -e 's|emacs/site-lisp|${EMACS_NAME}/${EMACS_VER}/site-lisp|g' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
