# New ports collection makefile for:    ja-emacs-manual
# Version required:     13
# Date created:         14 April 1999
# Whom:                 OKAZAKI Tetsurou
#
# $FreeBSD$
#

DISTNAME=	emacs-20.4-man-jp
PKGNAME=	ja-emacs-manual-13.1999.09.12
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/GNU/
EXTRACT_SUFX=	.tgz

MAINTAINER=	okazaki@be.to

BUILD_DEPENDS=	emacs-20.4:${PORTSDIR}/editors/emacs20 \
		/nonexistent:${PORTSDIR}/editors/emacs20:checksum

# EMACS_ARC is fetched by BUILD_DEPENDS
EMACS_DISTNAME= emacs-20.4
EMACS_ARC=	${EMACS_DISTNAME}.tar.gz
EMACS_SRCDIR=	${WRKDIR}/${EMACS_DISTNAME}
EXTRACT_FILES=	${EMACS_DISTNAME}/man/ack.texi \
		${EMACS_DISTNAME}/lisp/textmodes/texinfmt.el

# We use emacs20 to format texinfo files.
EMACS=		emacs-20.4
FORMAT_FLAG=	t

MAKE_ENV=	EMACS="${EMACS}" FORMAT_FLAG="${FORMAT_FLAG}"

post-extract:
	@${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	@(cd ${WRKDIR} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${EMACS_ARC} ${EXTRACT_AFTER_ARGS} ${EXTRACT_FILES} ; \
	${CP} ${EXTRACT_FILES} ${WRKSRC})
	@${MKDIR} ${WRKDIR}/info

pre-patch:
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/patch-texinfmt.el

pre-build:
	@${ECHO_MSG} "===>   Now start formatting texinfo. Please wait."

post-build:
	@${ECHO_MSG} "===>   Done."

post-install:
	install-info ${PREFIX}/info/emacs-ja ${PREFIX}/info/dir

.include <bsd.port.mk>
