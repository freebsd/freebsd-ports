# New ports collection makefile for:	jp-groff
# Version required:	1.10+0.99
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id$
#

DISTNAME=	groff-1.10
PKGNAME=	jp-groff-0.99
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=	graphite@taurus.bekkoame.or.jp

PATCH_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://ftp.iij.ad.jp/pub/linux-j/JF/misc/
PATCHFILES=	jgroff-0.99.diff.gz
PATCH_DIST_STRIP=	-p1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
