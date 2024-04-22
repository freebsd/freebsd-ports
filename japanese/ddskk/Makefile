PORTNAME=	ddskk
DISTVERSION=	17.1.20230702
PORTREVISION=	1
CATEGORIES=	japanese elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Kana to Kanji conversion program on Emacsen
WWW=		http://openlab.ring.gr.jp/skk/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs

USE_GITHUB=	yes
GH_ACCOUNT=	skk-dev
GH_TAGNAME=	8c47f46

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS.ja CODENAME.ja Contributors Development.ja.org FAQ.ja NEWS.ja history.md
	${INSTALL_DATA} ${WRKSRC}/READMEs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in dot.emacs dot.skk
	${INSTALL_DATA} ${WRKSRC}/etc/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
