# New ports collection makefile for:	skk-elisp
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ddskk
PORTVERSION=	13.1
PORTREVISION=	5
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/ \
		ftp://ftp.ring.gr.jp/pub/elisp/skk/maintrunk/ \
		http://www.ring.gr.jp/archives/elisp/skk/maintrunk/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Kana to Kanji conversion program on Emacsen

USE_EMACS=      yes

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
.if (${EMACS_PORT_NAME} == "emacs23")
DEPPORT_SUFFIX=
.else
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
.endif
BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emu/emu.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX}
RUN_DEPENDS=	${BUILD_DEPENDS}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

INFO=		skk

SKK_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/skk
SKK_DOCS=	AUTHORS.ja CODENAME.ja Contributors FAQ.ja NEWS.ja README
SKK_EXAMPLES=	etc/Emacs.ad etc/dot.emacs etc/dot.skk

ALL_TARGET=	elc info
MAKE_ARGS+=	SKK_LISPDIR=${PREFIX}/${SKK_LISPDIR}

post-install:
.for i in skk-jisx0213 skk-lookup
	${INSTALL_DATA} ${WRKSRC}/${i}.el ${PREFIX}/${SKK_LISPDIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for i in ${SKK_EXAMPLES}
	${INSTALL_DATA}	${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${SKK_DOCS}
	${INSTALL_DATA} ${WRKSRC}/READMEs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
