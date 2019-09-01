# Created by: Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	ddskk
DISTVERSION=	16.2
PORTREVISION=	4
CATEGORIES=	japanese elisp
MASTER_SITES=	ftp://ftp.ring.gr.jp/pub/elisp/skk/maintrunk/ \
		http://www.ring.gr.jp/archives/elisp/skk/maintrunk/ \
		http://openlab.ring.gr.jp/skk/maintrunk/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Kana to Kanji conversion program on Emacsen

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/READMEs/COPYING

USES=		emacs

MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}" \
		SKK_LISPDIR="${STAGEDIR}${PREFIX}/${SKK_LISPDIR}" \
		SKK_INFODIR="${STAGEDIR}${PREFIX}/${INFO_PATH}"
ALL_TARGET=	elc info
NO_ARCH=	yes

INFO=		skk
PORTDOCS=	*
PORTEXAMPLES=	*

SKK_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/skk

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		'/skk-tut-file/s|@TUT@|${PREFIX}/share/skk/SKK.tut|' \
		${WRKSRC}/skk-setup.el.in

pre-build:
.for i in skk-lookup.el skk-jisx0213.el
	@${MV} ${WRKSRC}/${i} ${WRKDIR}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SKK_LISPDIR}
.for i in skk-lookup.el skk-jisx0213.el
	${INSTALL_DATA} ${WRKDIR}/${i} ${STAGEDIR}${PREFIX}/${SKK_LISPDIR}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS.ja CODENAME.ja Contributors Development.ja.org FAQ.ja NEWS.ja
	${INSTALL_DATA} ${WRKSRC}/READMEs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in Emacs.ad dot.emacs dot.skk
	${INSTALL_DATA} ${WRKSRC}/etc/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
