# New ports collection makefile for:    ja-emacs-manual
# Version required:     13
# Date created:         14 April 1999
# Whom:                 OKAZAKI Tetsurou
#
# $Id$
#

DISTNAME=	emacs-20.3-man-jp
PKGNAME=	ja-emacs-manual-13.1998.11.25
CATEGORIES=	japanese
MASTER_SITES=	http://www.ascii.co.jp/pub/GNU/
DISTFILES=	${EXTRACT_ONLY} ${EMACS_ARC}

MAINTAINER=	okazaki@be.to

BUILD_DEPENDS=	emacs-20.3:${PORTSDIR}/editors/emacs20

EXTRACT_ONLY=	${DISTNAME}.tgz

EMACS_DISTNAME= emacs-20.3
EMACS_ARC=	${EMACS_DISTNAME}.tar.gz
EMACS_SRCDIR=	${WRKDIR}/${EMACS_DISTNAME}
EXTRACT_FILES=	${EMACS_DISTNAME}/man/ack.texi \
		${EMACS_DISTNAME}/lisp/textmodes/texinfmt.el

# We use emacs20 to format texinfo files.
EMACS=		emacs-20.3
FORMAT_FLAG=	t

MAKE_ENV=	EMACS="${EMACS}" FORMAT_FLAG="${FORMAT_FLAG}"

post-extract:
	@${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	@(cd ${WRKDIR} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${EMACS_ARC} ${EXTRACT_AFTER_ARGS} ${EXTRACT_FILES})
	@${CP} ${EMACS_SRCDIR}/man/ack.texi ${WRKSRC}/ack.texi
	@${CP} ${EMACS_SRCDIR}/lisp/textmodes/texinfmt.el ${WRKSRC}/texinfmt.el

pre-patch:
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/patch-texinfmt.el

post-patch:
	@(cd ${WRKSRC} && ${MV} texinfmt.el texinfmt.el.tmp && \
	  ${SED} -e 's/START-INFO-DIR-ENTRY\\n\\n/START-INFO-DIR-ENTRY\\n/g' \
	  texinfmt.el.tmp > texinfmt.el)

pre-build:
	@${ECHO_MSG} "===>   Now start formatting texinfo. Please wait."

post-build:
	@${ECHO_MSG} "===>   Done."

post-install:
	install-info ${PREFIX}/info/emacs-ja ${PREFIX}/info/dir

.include <bsd.port.mk>
