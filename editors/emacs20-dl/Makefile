# New ports collection makefile for:	GNU emacs with dynamic loading function
# Date created:		10 October 1998
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	emacs-dl
PORTVERSION=	${EMACS_VER}
PORTREVISION=	2
CATEGORIES=	editors ipv6
MASTER_SITES=	http://www.ainet.or.jp/~inoue/software/emacs-xim/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs
DISTNAME=	emacs-${EMACS_VER}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${XIM_PATCH}${EXTRACT_SUFX}

PATCH_SITES=		ftp://ftp.m17n.org/pub/mule/dynamic-loading/ \
			http://www.etl.go.jp/~tomo/comp/emacsen/ \
			${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	. shige/emacs
PATCHFILES=		emacs-20.4-dl3.diff.gz emacs-20.7-linespace-patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	shige@FreeBSD.org
COMMENT=	GNU editing macros with dynamic loading module function (binary only)

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
CONFIGURE_ARGS+=	--with-line-space

# for XIM extension
XIM_PATCH=	emacs20-xim-20000713
.if defined(WITHOUT_XIM) && (${WITHOUT_XIM} == "yes")
MAKE_FLAGS=	MYCPPFLAG="-DX_I18N_INHIBITED"
.endif

DOC_FILE=	DOC-DL-${EMACS_VER}.1

PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET} \
		DOC_FILE=${DOC_FILE}

SCRIPTS_ENV=	SED=${SED} MV=${MV} \
		DOC_FILE=${DOC_FILE}

.include <bsd.port.pre.mk>

.if defined(WITH_XPG4)
.if ${OSVERSION} >= 220000 && ${OSVERSION} < 400020 || \
	${OSVERSION} >= 500000 && ${OSVERSION} < 500005
CONFIGURE_ARGS+=	--with-xpg4
.endif
.endif

RECOMPILE_ELS=	dired.el startup.el

pre-patch:
	@(cd ${WRKSRC} ; \
	  ${PATCH} ${PATCH_ARGS} -p1 < ../${XIM_PATCH}/${XIM_PATCH}.diff ;\
	)

pre-build:
	@${RM} -rf ${WRKSRC}/info/*
	@${LN} -sf DOC ${WRKSRC}/etc/${DOC_FILE}

post-build:
# to rebuild emacs because startup.elc should be updated
	@(cd ${WRKSRC}/lisp; \
		${WRKSRC}/src/emacs -batch -q -no-init-file \
			-f batch-byte-compile ${RECOMPILE_ELS} ; \
	)
	@${RM} -f ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${EMACS_VER}*
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET} ;\
	)

do-install:
	@${INSTALL} -c -s -m 555 -o root -g wheel ${WRKSRC}/src/emacs ${PREFIX}/bin/emacs-dl-${EMACS_VER}
	@${INSTALL_DATA} ${WRKSRC}/etc/DOC ${PREFIX}/share/emacs/${EMACS_VER}/etc/${DOC_FILE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
