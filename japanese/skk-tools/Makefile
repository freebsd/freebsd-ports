# New ports collection makefile for:	skk-tools
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skk-tools
PORTVERSION=	1.1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/skk/tools/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	text/elisp/skk/tools
DISTNAME=	skktools-${PORTVERSION}

MAINTAINER=	matusita@FreeBSD.org
COMMENT=Jisyo-tools for the SKK Japanese-input software

USE_BZIP2=	yes
.if defined(WITHOUT_GNOME)
CONFIGURE_ARGS=	--without-skkdic-expr2
.else
USE_GNOME=	glib20
.endif

GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/skk

.if defined(WITHOUT_GNOME)
PLIST_SUB+=	WITHOUT_GNOME:="@comment "
.else
PLIST_SUB+=	WITHOUT_GNOME:=""
.endif

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/READMEs/README.C ${DOCSDIR}/README.skktools
.if !defined(WITHOUT_GNOME)
	${INSTALL_DATA} ${WRKSRC}/READMEs/README.skkdic-expr2 ${DOCSDIR}
.endif

.include <bsd.port.mk>
