# New ports collection makefile for:	JNetHack 3.4.x
# Date created:		16 June 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese games

MAINTAINER=	knu@FreeBSD.org

MASTERDIR=	${.CURDIR}/../../games/nethack34

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
MD5_FILE=	${.CURDIR}/distinfo
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PATCH_SITES=	http://downloads.sourceforge.jp/jnethack/606/
PATCHFILES=	jnethack-${PORTVERSION}-0.6.diff.gz
PATCH_DIST_STRIP=	-p1

post-install: jnethack-post-install

jnethack-post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/nethack
.for i in README.j ChangeLog.j INSTALL.j
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/ja/nethack
.endfor
.endif

.include "${MASTERDIR}/Makefile"
