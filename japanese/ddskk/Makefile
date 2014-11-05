# Created by: Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	ddskk
PORTVERSION=	15.1
PORTREVISION=	2
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/ \
		ftp://ftp.ring.gr.jp/pub/elisp/skk/maintrunk/ \
		http://www.ring.gr.jp/archives/elisp/skk/maintrunk/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Kana to Kanji conversion program on Emacsen

LICENSE=	GPLv2

NO_ARCH=	yes

USE_EMACS=	yes
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}" \
		SKK_LISPDIR="${STAGEDIR}${PREFIX}/${SKK_LISPDIR}" \
		SKK_INFODIR="${STAGEDIR}${PREFIX}/${INFO_PATH}"
ALL_TARGET=	elc info

INFO=		skk
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

SKK_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/skk

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
	(cd ${WRKDIR} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/${SKK_LISPDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS.ja CODENAME.ja Contributors FAQ.ja NEWS.ja README
	(cd ${WRKSRC}/READMEs && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in Emacs.ad dot.emacs dot.skk
	(cd ${WRKSRC}/etc && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
