# New ports collection makefile for:	jless
# Version required:	332
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.10 1997/09/14 21:34:52 max Exp $
#

DISTNAME=	less-332
PKGNAME=	ja-less-332
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GNU}

PATCH_SITES=	ftp://ftp.aist-nara.ac.jp/pub/misc/less/
PATCHFILES=	less-332-iso221.patch.gz \
		less-332-iso221-222.patch.gz \
		less-332-iso222-224.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	nobu@psrc.isac.co.jp

GNU_CONFIGURE=	yes
MAN1=		jless.1 jlesskey.1

.include <bsd.port.mk>
