# New ports collection makefile for:	gxditview (part of jp-groff)
# Version required:	1.09+0.98
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id$
#

DISTNAME=	groff-1.09
PKGNAME=	jp-gxditview-0.98
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=	asami@FreeBSD.ORG

PATCH_SITES=	ftp://ftp.iij.ad.jp/pub/NetNews/fj.sources/volume95/Apr/
PATCHFILES=	jgroff-0.98.diff.gz
DISTPATCHES=	950414.01.Z 950414.02.Z
PATCH_DIST_ARGS?=	-d ${WRKSRC}/.. --forward --quiet -E -p1

USE_IMAKE=	yes
WRKSRC=${.CURDIR}/work/${DISTNAME}/xditview

.include <bsd.port.mk>
