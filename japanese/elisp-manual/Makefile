# New ports collection makefile for:    ja-elisp-manual
# Date created:         28 Mar 2000
# Whom:                 OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	elisp-manual
PORTVERSION=	2.5.20000508
CATEGORIES=	japanese lang
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/GNU/elisp-manual-20/
DISTNAME=	elisp-manual-20-2.5-jp
EXTRACT_SUFX=	.tgz

PATCH_SITES=	ftp://ftp.ascii.co.jp/pub/GNU/elisp-manual-20/
PATCHFILES=	elisp-manual-20-2.5-jp.ERRATA.000422.jis \
		elisp-manual-20-2.5-jp.ERRATA.000508.jis

MAINTAINER=	okazaki@be.to

EMACS_PORT_NAME=	emacs20
EMACS_NO_RUN_DEPENDS=	YES

# emacs port setup

EXTRA_FILES=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/lisp/textmodes/texinfmt.el

# We must apply this patch at first.
EXTRA_PATCHES=	${WRKSRC}/patch-texinfmt.el

post-extract:
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/PORT_TEXIFMT.MK ${WRKSRC}
	${CP} ${EXTRA_FILES} ${WRKSRC}
	${MKDIR} ${WRKDIR}/info
	${LN} -sf index.unperm ${WRKSRC}/index.texi

pre-patch:
	@(cd ${WRKSRC} && \
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-texinfmt.el.patch ; \
	)

post-patch:
	cd ${WRKSRC} && \
	${PERL} -pi -e 's/(@[^@]*ref{.*,.*,.*, *emacs),/$$1-ja,/;' *.texi

pre-build:
	@${ECHO_MSG} "===>   Now start formatting texinfo. Please wait."

post-build:
	@${ECHO_MSG} "===>   Done."

post-install:
	install-info ${PREFIX}/info/elisp-ja ${PREFIX}/info/dir

.include <bsd.port.mk>
