# New ports collection makefile for:	GNU emacs with dl
# Date created:		10 October 1998
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	emacs-dl
PORTVERSION=	20.7
CATEGORIES=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs
DISTNAME=	emacs-${PORTVERSION}

PATCH_SITES=	ftp://ftp.m17n.org/pub/mule/dynamic-loading/ \
		http://www.etl.go.jp/~tomo/comp/emacsen/
PATCHFILES=	emacs-20.4-dl3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	shige@FreeBSD.org

RUN_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20

WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}

USE_AUTOCONF=	yes
USE_GMAKE=	yes
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
EMACS_VER=	20.7
CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
.if !defined(WITHOUT_X11)
CONFIGURE_ARGS=	--with-x-toolkit --with-pop
USE_XLIB=	yes
.else
CONFIGURE_ARGS=	--with-x=no --with-pop
.endif

DOC_FILE=	DOC-DL-${EMACS_VER}.1

PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET} \
		DOC_FILE=${DOC_FILE}

SCRIPTS_ENV=	SED=${SED} MV=${MV} \
		DOC_FILE=${DOC_FILE}

.if defined(WITH_XPG4)
.if ${OSVERSION} >= 220000 && ${OSVERSION} < 400020
CONFIGURE_ARGS+=	--with-xpg4
.endif
.if ${OSVERSION} >= 500000 && ${OSVERSION} < 500005
CONFIGURE_ARGS+=	--with-xpg4
.endif
.endif

pre-build:
	@${RM} -rf ${WRKSRC}/info/*
	@${LN} -sf DOC ${WRKSRC}/etc/${DOC_FILE}

do-install:
	@${INSTALL} -c -s -m 555 -o root -g wheel ${WRKSRC}/src/emacs ${PREFIX}/bin/emacs-dl-${EMACS_VER}
	@${INSTALL_DATA} ${WRKSRC}/etc/DOC ${PREFIX}/share/emacs/${EMACS_VER}/etc/${DOC_FILE}

.include <bsd.port.mk>
