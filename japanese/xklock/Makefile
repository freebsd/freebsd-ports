# New ports collection makefile for:	xklock
# Version required:	2.54
# Date created:		20 April 1997
# Whom:			nkazushi@highway.or.jp
#
# $Id: Makefile,v 1.3 1998/10/16 04:15:59 jseger Exp $
#

DISTNAME=	xklock-2.7
PKGNAME=	ja-xklock-2.7.1
CATEGORIES=	x11 japanese
MASTER_SITES=	ftp://ftp.tk.mesh.ad.jp/pub/Linux/JE-sources/X/  \
		ftp://ftp.biol.tsukuba.ac.jp/pub/X/clients/  \
		ftp://ftp.kagoshima-u.ac.jp/pub1/PC/linux-j/JE-sources/X/  \
		ftp://ftp.hitachi.co.jp/pub/linux/colias/pub/linux/JE-0.9.6/sources/X/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	xklock-2.7+lx.diff.gz
PATCH_DIST_STRIP=	-p1

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

MAINTAINER=	nkazushi@highway.or.jp

BROKEN_ELF=	yes

WRKSRC=	${WRKDIR}
USE_X_PREFIX=	yes

pre-configure:
	@${MV} ${WRKDIR}/jnames.c ${WRKDIR}/jnames.c.in
	@${SED} -e "s:/usr/local:${PREFIX}:" ${WRKDIR}/jnames.c.in  \
		> ${WRKDIR}/jnames.c
	@${MV} ${WRKDIR}/xklock.h ${WRKDIR}/xklock.h.in
	@${SED} -e "s:/usr/local:${PREFIX}:" ${WRKDIR}/xklock.h.in  \
		> ${WRKDIR}/xklock.h

post-install:
	${TOUCH} ${PREFIX}/lib/jnames

.include <bsd.port.mk>
