# New ports collection makefile for:	kon
# Version required:	0.01
# Date created:		7 June 1995
# Whom:			Takashi Ogura <ogura@st.rim.or.jp>
#
# $Id$
#

DISTNAME=	kon
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/linux-j/JE-sources/JE/
DISTFILES=	kon-0.99.4e.tgz

FONT_SITE=	ftp://ftp.iij.ad.jp/pub/X/XFree86/XFree86/3.1.1/untarred/xc/fonts/bdf/misc/
FONTFILES=	k14.bdf 7x14rk.bdf

MAINTAINER=	asami@FreeBSD.ORG

USE_GMAKE=	yes

pre-fetch: 
	@(cd ${DISTDIR}; \
	for file in ${FONTFILES} ; do \
		if [ ! -f $$file ]; then \
			if ${NCFTP} ${NCFTPFLAGS} ${FONT_SITE}$$file; then \
				break; \
			fi \
		fi \
	done)

post-configure:
	sed -e 's%%CURDIR%%${.CURDIR}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  files/dotconfig > ${WRKSRC}/.config

post-install:
	gzip -9nf ${PREFIX}/man/ja_JP.ujis/man1/kon.1

.include <bsd.port.mk>
