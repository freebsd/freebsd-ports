# New ports collection makefile for:	mule with Canna
# Version required:	2.3
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.28 1997/05/28 03:06:35 asami Exp $
#

DISTNAME=	mule-2.3
PKGNAME=	jp-cmule-2.3
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/ \
		ftp://ftp.funet.fi/pub/gnu/emacs/mule/

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=        i386--freebsd --with-x-toolkit \
		--canna --canna-libraries=/usr/local/lib \
		--canna-includes=/usr/local/include --terminal-face \
		--locallisppath=${PREFIX}/lib/mule/site-lisp:${PREFIX}/share/emacs/site-lisp
STRIP=
MAN1=		coco.1 ctags.1 etags.1 m2ps.1 mule.1

pre-build:
	find ${WRKSRC} -name \*.orig -exec /bin/rm -f \{} \;

post-install:
# note that rcs-checkn and any2ps are scripts
.for file in b2m coco ctags etags m2ps mule-19.28
	strip ${PREFIX}/bin/${file}
.endfor
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  sed -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in emacs vip forms gnus cl sc
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# Our makeinfo can't handle files with Japanese characters. :<
	install-info --section="The Emacs editor and associated tools" --entry="* Antenews-jp: (antenews-jp).	Version 19 Antenews. (Japanese)" ${PREFIX}/info/antenews-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Mule: (mule).			Multilingual Enhancement to GNU Emacs." ${PREFIX}/info/mule ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Mule-jp: (mule-jp).		Multilingual Enhancement to GNU Emacs. (Japanese)" ${PREFIX}/info/mule-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Egg-jp: (egg-jp).		Japanese/Chinese Inputting Method. (Japanese)" ${PREFIX}/info/egg-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Canna-jp: (canna-jp).		Another Japanese Inputting Method. (Japanese)" ${PREFIX}/info/canna-jp ${PREFIX}/info/dir

.include <bsd.port.mk>
