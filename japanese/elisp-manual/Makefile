# New ports collection makefile for:    ja-elisp-manual
# Date created:         28 Mar 2000
# Whom:                 OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	elisp-manual
PORTVERSION=	2.5.20000508
PORTREVISION=	2
CATEGORIES=	japanese elisp lang
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/GNU/elisp-manual-20/
DISTNAME=	elisp-manual-20-2.5-jp
EXTRACT_SUFX=	.tgz

PATCH_SITES=	ftp://ftp.ascii.co.jp/pub/GNU/elisp-manual-20/
PATCHFILES=	elisp-manual-20-2.5-jp.ERRATA.000422.jis \
		elisp-manual-20-2.5-jp.ERRATA.000508.jis

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese translation of the GNU Emacs Lisp Reference Manual

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_EMACS=	yes
EMACS_PORT_NAME=	emacs21
EMACS_NO_RUN_DEPENDS=	YES

# emacs port setup

TEXINFMT_EL=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/lisp/textmodes/texinfmt.el

# We must apply this patch at first.
EXTRA_PATCHES=	${WRKSRC}/patch-texinfmt.el

EXTRACT_DEPENDS+=	${TEXINFMT_EL}:${EMACS_PORTSDIR}

INFO=	elisp-ja
TEXINFO=	elisp.texi

EMACS_ARGS=	-batch -nw --multibyte -no-init-file -no-site-file
EMACS_LOADLIBS=	--load=texinfmt.el --load=PORT_TEXIFMT.MK

post-extract:
	${CP} ${FILESDIR}/PORT_TEXIFMT.MK ${WRKSRC}
	${CP} ${TEXINFMT_EL} ${WRKSRC}
	${MKDIR} ${WRKDIR}/info
	${LN} -sf index.unperm ${WRKSRC}/index.texi

pre-patch:
	cd ${WRKSRC}; \
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-texinfmt.el.patch

post-patch:
	cd ${WRKSRC}; \
	${REINPLACE_CMD} -E -e 's/(@[^@]*ref{.*,.*,.*, *emacs),/\1-ja,/;' *.texi

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

.include <bsd.port.mk>
