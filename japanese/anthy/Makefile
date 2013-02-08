# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anthy
PORTVERSION=	9100h
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/37536
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	anthy
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Another Kana-Kanji conversion system

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/alt-cannadic/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	lthack
USE_PKGCONFIG=	build

DOCSDIR=	share/doc/ja/anthy
ELISPDIR=	share/emacs/site-lisp/anthy
PLIST_SUB=	ELISPDIR=${ELISPDIR}

OPTIONS_DEFINE=	2CHDIC ODIC GSKKDIC DOCS
OPTIONS_DEFAULT=	DOCS

2CHDIC_DESC=	2ch Dictionary
ODIC_DESC=	Okinawa Dictionary
GSKKDIC_DESC=	SKK Dictionary

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M2CHDIC}
MASTER_SITES+=	http://omaemona.sourceforge.net/packages/Zisyo/:2chdic
DISTFILES+=	2ch.t:2chdic
.endif

.if ${PORT_OPTIONS:MODIC}
MASTER_SITES+=	http://www.ofug.net/~yamajun/files/:odic
DISTFILES+=	${ODIC_SRCS}:odic
ODIC_SRCS=	${ODIC_VERS}.t
ODIC_VERS=	okinawa-20070717
.endif

.if ${PORT_OPTIONS:MGSKKDIC}
MASTER_SITES+=	http://www.ohnolab.org/~kimoto/:gskk
DISTFILES+=	${GSKK_SRCS}:gskk
GSKK_SRCS=	${GSKK_VERS}.t.gz
GSKK_VERS=	gskk-20041208
.endif

post-extract:
.if ${PORT_OPTIONS:M2CHDIC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/2ch.t ${WRKSRC}/mkworddic
	${PRINTF} "/mkworddic\\\\/base.t/a\\\\\\nread @top_srcdir@/mkworddic/2ch.t\\n" | \
	${REINPLACE_CMD} -f /dev/stdin ${WRKSRC}/mkworddic/dict.args.in
.endif

.if ${PORT_OPTIONS:MODIC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${ODIC_SRCS} ${WRKSRC}/mkworddic
	${PRINTF} "/mkworddic\\\\/base.t/a\\\\\\nread @top_srcdir@/mkworddic/${ODIC_SRCS}\\n" | \
	${REINPLACE_CMD} -f /dev/stdin ${WRKSRC}/mkworddic/dict.args.in
.endif

.if ${PORT_OPTIONS:MGSKKDIC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${GSKK_SRCS} ${WRKSRC}/mkworddic
	${GUNZIP_CMD} ${WRKSRC}/mkworddic/${GSKK_SRCS}
	${PRINTF} "/mkworddic\\\\/base.t/a\\\\\\nread @top_srcdir@/mkworddic/${GSKK_VERS}.t\\n" | \
	${REINPLACE_CMD} -f /dev/stdin ${WRKSRC}/mkworddic/dict.args.in
.endif

post-patch:
	${REINPLACE_CMD} -e \
		's| install-lispLISP||g' ${WRKSRC}/src-util/Makefile.in
	${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el ${PREFIX}/${ELISPDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${PREFIX}/${DOCSDIR}
.endif

.include <bsd.port.mk>
