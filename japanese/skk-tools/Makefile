# New ports collection makefile for:	skk-tools
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

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

OPTIONS=	EXPR2 "Build skkdic-expr2 (needs glib-2.x)" on

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/skk

PORTDOCS=	README.skktools
PLIST_FILES=	bin/skkdic-count bin/skkdic-expr bin/skkdic-sort

.include <bsd.port.options.mk>

.if defined(WITHOUT_EXPR2)
CONFIGURE_ARGS=	--without-skkdic-expr2
.else
USE_GNOME=	glib20
PORTDOCS+=	README.skkdic-expr2
PLIST_FILES+=	bin/skkdic-expr2
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/READMEs/README.C ${DOCSDIR}/README.skktools
.if !defined(WITHOUT_EXPR2)
	${INSTALL_DATA} ${WRKSRC}/READMEs/README.skkdic-expr2 ${DOCSDIR}
.endif
.endif

.include <bsd.port.mk>
