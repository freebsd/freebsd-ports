# New ports collection makefile for:	kon
# Version required:	0.01
# Date created:		7 June 1995
# Whom:			Takashi Ogura <ogura@st.rim.or.jp>
#
# $Id: Makefile,v 1.4 1995/08/05 18:19:04 ats Exp $
#

DISTNAME=	kon
PKGNAME=	kon-0994e
CATEGORIES+=	japanese
# note kon is only in first directory and fonts are only in second directory
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/linux-j/JE-sources/JE/ \
		ftp://ftp.iij.ad.jp/pub/X/XFree86/XFree86/3.1.1/untarred/xc/fonts/bdf/misc/
DISTFILES=	kon-0.99.4e.tgz k14.bdf 7x14rk.bdf
EXTRACT_ONLY=	kon-0.99.4e.tgz

MAINTAINER=	asami@FreeBSD.ORG

USE_GMAKE=	yes

post-configure:
	sed -e 's%%CURDIR%%${.CURDIR}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  -e 's%%DISTDIR%%${DISTDIR}' \
	  files/dotconfig > ${WRKSRC}/.config

post-install:
	gzip -9nf ${PREFIX}/man/ja_JP.ujis/man1/kon.1

.include <bsd.port.mk>
