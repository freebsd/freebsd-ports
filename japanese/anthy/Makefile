# New ports collection makefile for:   anthy
# Date created:        26 February 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anthy
PORTVERSION=	7500
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/19158
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	anthy
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Another kana-kanji conversion system

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnometarget lthack pkgconfig

DOCSDIR=	share/doc/ja/anthy
ELISPDIR=	share/emacs/site-lisp/anthy
PLIST_SUB=	ELISPDIR=${ELISPDIR}

.if defined(WITH_2CHDIC)
MASTER_SITES+=	http://omaemona.sourceforge.net/packages/Zisyo/:2chdic
DISTFILES+=	2ch.t:2chdic
.endif

.if defined(WITH_ODIC)
MASTER_SITES+=	http://www.ofug.net/~yamajun/files/:odic
EXTRACT_ONLY+=	${ODIC_SRCS}
DISTFILES+=	${ODIC_SRCS}:odic
ODIC_SRCS=	${ODIC_VERS}.tar.gz
ODIC_VERS=	okinawa-20051104
.endif

.if defined(WITH_GSKKDIC)
MASTER_SITES+=	http://www.ohnolab.org/~kimoto/:gskk
DISTFILES+=	${GSKK_SRCS}:gskk
GSKK_SRCS=	${GSKK_VERS}.t.gz
GSKK_VERS=	gskk-20041208
.endif

post-extract:
.if defined(WITH_2CHDIC)
	${CP} ${DISTDIR}/${DIST_SUBDIR}/2ch.t ${WRKSRC}/mkworddic
	${PRINTF} "/mkworddic\\\\/placename.t/a\\\\\\nread @top_srcdir@/mkworddic/2ch.t\\n" | \
	${REINPLACE_CMD} -f /dev/stdin ${WRKSRC}/mkworddic/dict.args.in
.endif

.if defined(WITH_ODIC)
	${CP} ${WRKDIR}/${ODIC_VERS}/okinawa.t ${WRKSRC}/mkworddic
	${PRINTF} "/mkworddic\\\\/placename.t/a\\\\\\nread @top_srcdir@/mkworddic/okinawa.t\\n" | \
	${REINPLACE_CMD} -f /dev/stdin ${WRKSRC}/mkworddic/dict.args.in
.endif

.if defined(WITH_GSKKDIC)
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${GSKK_SRCS} ${WRKSRC}/mkworddic
	${GUNZIP_CMD} ${WRKSRC}/mkworddic/${GSKK_SRCS}
	${PRINTF} "/mkworddic\\\\/placename.t/a\\\\\\nread @top_srcdir@/mkworddic/${GSKK_VERS}.t\\n" | \
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${PREFIX}/${DOCSDIR}
.endif

.include <bsd.port.mk>
