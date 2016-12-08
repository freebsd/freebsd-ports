# Created by: Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	skk-tools
PORTVERSION=	1.3.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/skk/tools/
DISTNAME=	skktools-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jisyo-tools for the SKK Japanese-input software

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/skk

PORTDOCS=	README.skktools
PLIST_FILES=	bin/skkdic-count bin/skkdic-expr bin/skkdic-sort

OPTIONS_DEFINE=		DOCS EXPR2
OPTIONS_DEFAULT=	EXPR2

EXPR2_DESC=		Build skkdic-expr2 (needs glib-2.x)
EXPR2_USES=		pkgconfig
EXPR2_USE=		GNOME=glib20
EXPR2_PLIST_FILES=	bin/skkdic-expr2
EXPR2_CONFIGURE_WITH=	skkdic-expr2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXPR2}
PORTDOCS+=	README.skkdic-expr2
.endif

post-build:
	@${LN} -sf README.C ${WRKSRC}/READMEs/README.skktools

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC}/READMEs && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
