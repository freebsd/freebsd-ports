# New ports collection makefile for:	jless
# Version required:	332
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.11 1998/01/23 07:53:38 itojun Exp $
#

DISTNAME=	less-332
PKGNAME=	ja-less-332
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GNU}

PATCH_SITES=	ftp://ftp.tokyonet.ad.jp/pub/misc/less/
PATCHFILES=	less-332-iso233.patch.gz \
		less-332-iso233-235.patch.gz \
		less-332-iso235-237.patch.gz \
		less-332-iso237-238.patch.gz \
		less-332-iso238-240.patch.gz \

PATCH_DIST_STRIP=	-p1

MAINTAINER=	nobu@psrc.isac.co.jp

GNU_CONFIGURE=	yes
MAN1=		jless.1 jlesskey.1

.include <bsd.port.mk>
