# New ports collection makefile for:    ja-emacs-manual
# Date created:         14 April 1999
# Whom:                 OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	emacs-manual
PORTVERSION=	13.20000303
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/GNU/emacs-20.x/:ascii \
		${MASTER_SITE_GNU:S/$/:gnu/}
MASTER_SITE_SUBDIR=	emacs/:gnu
DISTNAME=	emacs-20.6-man-jp
DISTFILES=	${DISTNAME}.tgz:ascii ${EMACS_ARC:S/$/:gnu/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese translation of the GNU Emacs Manual

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_EMACS=	yes
EMACS_PORT_NAME=	emacs20
EMACS_NO_RUN_DEPENDS=	YES

ERRATA_FILE=

EXTRACT_ONLY=	${DISTNAME}.tgz
EMACS_DISTNAME=	emacs-${EMACS_VER}
EMACS_ARC=	${EMACS_DISTNAME}.tar.gz
EMACS_SRCDIR=	${WRKDIR}/${EMACS_DISTNAME}
EXTRACT_FILES=	${EMACS_DISTNAME}/man/ack.texi
TEXINFMT_EL=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/lisp/textmodes/texinfmt.el

# We must apply this patch at first.
EXTRA_PATCHES=	${WRKSRC}/patch-texinfmt.el

.if defined(ERRATA_FILE) && !empty(ERRATA_FILE)
DISTFILES+=	${ERRATA_FILE}.tgz
EXTRACT_ONLY+=	${ERRATA_FILE}.tgz
EXTRA_PATCHES+=	${WRKDIR}/${ERRATA_FILE}
.endif

EXTRACT_DEPENDS+=	${TEXINFMT_EL}:${EMACS_PORTSDIR}

INFO=	emacs-ja
TEXINFO=	emacs.texi

EMACS_ARGS=	-batch -nw --multibyte -no-init-file -no-site-file
EMACS_LOADLIBS=	--load=texinfmt.el --load=PORT_TEXIFMT.MK

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING)
.if ${OSVERSION} < 500000
IGNORE=		is broken: hangs during build
.endif
.endif

post-extract:
	${CP} ${FILESDIR}/PORT_TEXIFMT.MK ${WRKSRC}
	@(cd ${WRKDIR} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${EMACS_ARC} ${EXTRACT_AFTER_ARGS} ${EXTRACT_FILES} ; \
	${CP} ${EXTRACT_FILES} ${WRKSRC})
	${CP} ${TEXINFMT_EL} ${WRKSRC}
	${MKDIR} ${WRKDIR}/info

# workaround target (please delete after emacs-20.7-man-jp is released).
pre-patch:
	cd ${WRKSRC}; \
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-texinfmt.el.patch

post-patch:
	cd ${WRKSRC}; \
	${REINPLACE_CMD} -E -e 's/(@[^@]*ref{.*,.*,.*, *elisp),/\1-ja,/;' *.texi

pre-build:
	@${ECHO_MSG} "===>   Now start formatting texinfo. Please wait."

do-build:
	cd ${WRKSRC}; for f in ${TEXINFO}; do \
		${EMACS_CMD} ${EMACS_ARGS} ${EMACS_LOADLIBS} \
			--eval "(port-texinfo-format \"$$f\" 'junet)"; \
	done

post-build:
	@${ECHO_MSG} "===>   Done."

do-install:
.for i in ${INFO}
	${INSTALL_DATA} ${WRKDIR}/info/$i.info ${PREFIX}/${INFO_PATH}
.endfor

.include <bsd.port.post.mk>
