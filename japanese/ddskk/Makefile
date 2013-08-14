# Created by: Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	ddskk
PORTVERSION=	15.1
PORTREVISION=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/ \
		ftp://ftp.ring.gr.jp/pub/elisp/skk/maintrunk/ \
		http://www.ring.gr.jp/archives/elisp/skk/maintrunk/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Simple Kana to Kanji conversion program on Emacsen

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_EMACS=	yes
INFO=		skk

SKK_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/skk
PORTDOCS=	AUTHORS.ja CODENAME.ja Contributors FAQ.ja NEWS.ja README
PORTEXAMPLES=	Emacs.ad dot.emacs dot.skk

ALL_TARGET=	elc info
MAKE_ARGS+=	SKK_LISPDIR=${PREFIX}/${SKK_LISPDIR} SKK_INFODIR=${PREFIX}/${INFO_PATH}

pre-install:
	# required for non-standard PREFIX
	${MKDIR} ${PREFIX}/${SKK_LISPDIR}

.include <bsd.port.options.mk>

post-install:
.for i in skk-jisx0213 skk-lookup
	${INSTALL_DATA} ${WRKSRC}/${i}.el ${PREFIX}/${SKK_LISPDIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/READMEs/${i} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
.for i in ${PORTEXAMPLES}
	${INSTALL_DATA}	${WRKSRC}/etc/${i} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
