# New ports collection makefile for:   anthy
# Date created:        26 February 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anthy
PORTVERSION=	6700b
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/15414
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	anthy

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Another kana-kanji conversion system

USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_GNOME=	gnometarget lthack pkgconfig

DOCSDIR=	share/doc/ja/anthy
ELISPDIR=	share/emacs/site-lisp/anthy
PLIST_SUB=	ELISPDIR=${ELISPDIR}

.if defined(WITH_2CHDIC)
MASTER_SITES+=	http://omaemona.sourceforge.net/packages/Zisyo/:2chdic
DISTFILES+=	2ch.t:2chdic
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

.if defined(WITH_ODIC)
MASTER_SITES+=	http://www.ofug.net/~yamajun/files/:odic
DISTFILES+=	okinawa-20050410.t:odic
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

.if defined(WITH_GSKKDIC)
MASTER_SITES+=	http://www.ohnolab.org/~kimoto/:gskk
DISTFILES+=	gskk-20041208.t.gz:gskk
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

post-extract:
.if defined(WITH_2CHDIC)
	${CP} ${DISTDIR}/${DIST_SUBDIR}/2ch.t ${WRKSRC}/mkanthydic
	${REINPLACE_CMD} -e 's/base.t extra.t/base.t extra.t 2ch.t/' \
		${WRKSRC}/mkanthydic/Makefile.in
.endif

.if defined(WITH_ODIC)
	${CP} ${DISTDIR}/${DIST_SUBDIR}/okinawa-20050410.t ${WRKSRC}/mkanthydic
	${REINPLACE_CMD} -e \
		's/base.t extra.t/base.t extra.t okinawa-20050410.t/' \
		${WRKSRC}/mkanthydic/Makefile.in
.endif

.if defined(WITH_GSKKDIC)
	${CP} ${DISTDIR}/${DIST_SUBDIR}/gskk-20041208.t.gz ${WRKSRC}/mkanthydic
	${GUNZIP_CMD} ${WRKSRC}/mkanthydic/gskk-20041208.t.gz
	${REINPLACE_CMD} \
		-e 's/base.t extra.t/base.t extra.t gskk-20041208.t/' \
		${WRKSRC}/mkanthydic/Makefile.in
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
