# New ports collection makefile for:    ja-emacs-manual
# Date created:         14 April 1999
# Whom:                 OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	emacs-manual
PORTVERSION=	13.20000303
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/GNU/emacs-20.x/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs
DISTNAME=	emacs-20.6-man-jp
DISTFILES=	${DISTNAME}.tgz ${EMACS_ARC}

MAINTAINER=	okazaki@FreeBSD.org

EMACS_PORT_NAME=	emacs20
EMACS_NO_RUN_DEPENDS=	YES
USE_REINPLACE=	yes

ERRATA_FILE=

EXTRACT_ONLY=	${DISTNAME}.tgz
EMACS_DISTNAME=	emacs-${EMACS_VER}
EMACS_ARC=	${EMACS_DISTNAME}.tar.gz
EMACS_SRCDIR=	${WRKDIR}/${EMACS_DISTNAME}
EXTRACT_FILES=	${EMACS_DISTNAME}/man/ack.texi \
		${EMACS_DISTNAME}/lisp/textmodes/texinfmt.el

# We must apply this patch at first.
EXTRA_PATCHES=	${WRKSRC}/patch-texinfmt.el

.if defined(ERRATA_FILE) && !empty(ERRATA_FILE)
DISTFILES+=	${ERRATA_FILE}.tgz
EXTRACT_ONLY+=	${ERRATA_FILE}.tgz
EXTRA_PATCHES+=	${WRKDIR}/${ERRATA_FILE}
.endif

post-extract:
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/PORT_TEXIFMT.MK ${WRKSRC}
	@(cd ${WRKDIR} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${EMACS_ARC} ${EXTRACT_AFTER_ARGS} ${EXTRACT_FILES} ; \
	${CP} ${EXTRACT_FILES} ${WRKSRC})
	${MKDIR} ${WRKDIR}/info

# workaround target (please delete after emacs-20.7-man-jp is released).
pre-patch:
	@(cd ${WRKSRC} && \
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-texinfmt.el.patch ; \
	)

post-patch:
	cd ${WRKSRC} && \
	${REINPLACE_CMD} -E -e 's/(@[^@]*ref{.*,.*,.*, *elisp),/\1-ja,/;' *.texi

pre-build:
	@${ECHO_MSG} "===>   Now start formatting texinfo. Please wait."

post-build:
	@${ECHO_MSG} "===>   Done."

post-install:
	install-info ${PREFIX}/info/emacs-ja ${PREFIX}/info/dir

.include <bsd.port.mk>
