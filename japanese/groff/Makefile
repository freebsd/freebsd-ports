# New ports collection makefile for:	jp-groff
# Version required:	1.10+0.99
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.9 1997/01/24 10:18:53 asami Exp $
#

DISTNAME=	groff-1.10
PKGNAME=	jp-groff-0.99
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}

PATCH_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://ftp.iij.ad.jp/pub/linux-j/JF/misc/
PATCHFILES=	jgroff-0.99.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	graphite@taurus.bekkoame.or.jp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DESCS=		${WRKSRC}/devnippon/DESC.proto ${WRKSRC}/devps/DESC.in

#for not writing "/usr/local" explicitly in the patch
post-patch:
	@for f in ${DESCS}; do \
	  /bin/mv -f $${f} $${f}.tmp; \
	  ${SED} -e '$$d' $${f}.tmp > $${f}; \
	  case $${f} in \
  	    */devnippon/*) \
		${ECHO} "postpro ${PREFIX}/bin/grotty" >> $${f}; \
		;; \
	    */devps/*) \
		${ECHO} "postpro ${PREFIX}/bin/grops" >> $${f}; \
		;; \
	  esac; \
	done

.include <bsd.port.mk>
