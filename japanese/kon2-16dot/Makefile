# New ports collection makefile for:	kon
# Version required:	0.01
# Date created:		7 June 1995
# Whom:			Takashi Ogura <ogura@st.rim.or.jp>
#
# $Id: Makefile,v 1.3 1995/08/01 22:10:14 ats Exp $
#

DISTNAME=	kon
PKGNAME=	kon-0994e
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/linux-j/JE-sources/JE/
DISTFILES=	kon-0.99.4e.tgz
EXTRACT_ONLY=	kon-0.99.4e.tgz

.if !defined(MASTER_SITE_OVERRIDE)
FONT_SITE=	ftp://ftp.iij.ad.jp/pub/X/XFree86/XFree86/3.1.1/untarred/xc/fonts/bdf/misc/
FONTFILES=	k14.bdf 7x14rk.bdf
.else
DISTFILES +=	k14.bdf 7x14rk.bdf
.endif

MAINTAINER=	asami@FreeBSD.ORG

USE_GMAKE=	yes

.if !defined(MASTER_SITE_OVERRIDE)
pre-fetch: 
	@(cd ${DISTDIR}; \
	for file in ${FONTFILES} ; do \
		if [ ! -f $$file ]; then \
			if ${NCFTP} ${NCFTPFLAGS} ${FONT_SITE}$$file; then \
				break; \
			fi \
		fi \
	done)
.endif

post-configure:
	sed -e 's%%CURDIR%%${.CURDIR}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  files/dotconfig > ${WRKSRC}/.config

post-install:
	gzip -9nf ${PREFIX}/man/ja_JP.ujis/man1/kon.1

.include <bsd.port.mk>
