# Created by: Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	skk-tools
PORTVERSION=	1.3.2
PORTEPOCH=	1
CATEGORIES=	japanese
MASTER_SITES=	RINGSERVER/elisp/skk/tools \
		http://openlab.ring.gr.jp/skk/tools/
DISTNAME=	skktools-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jisyo-tools for the SKK Japanese-input software

LICENSE=	GPLv2

OPTIONS_DEFINE=	EXPR2
OPTIONS_DEFAULT=	EXPR2
EXPR2_DESC=	Build skkdic-expr2 (needs glib-2.x)

GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/skk

PORTDOCS=	README.skktools
PLIST_FILES=	bin/skkdic-count bin/skkdic-expr bin/skkdic-sort

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXPR2}
USE_GNOME=	glib20
USES+=		pkgconfig
PORTDOCS+=	README.skkdic-expr2
PLIST_FILES+=	bin/skkdic-expr2
.else
CONFIGURE_ARGS=	--without-skkdic-expr2
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/READMEs/README.C ${DOCSDIR}/README.skktools
.if ${PORT_OPTIONS:MEXPR2}
	${INSTALL_DATA} ${WRKSRC}/READMEs/README.skkdic-expr2 ${DOCSDIR}
.endif
.endif

.include <bsd.port.mk>
