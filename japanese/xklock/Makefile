# New ports collection makefile for:	xklock
# Date created:		20 April 1997
# Whom:			nkazushi@highway.or.jp
#
# $FreeBSD$
#

PORTNAME=	xklock
PORTVERSION=	2.7.1
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.tk.mesh.ad.jp/pub/Linux/JE-sources/X/  \
		ftp://ftp.biol.tsukuba.ac.jp/pub/X/clients/  \
		ftp://ftp.kagoshima-u.ac.jp/pub1/PC/linux-j/JE-sources/X/  \
		ftp://ftp.hitachi.co.jp/pub/linux/colias/pub/linux/JE-0.9.6/sources/X/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}+lx.diff.gz
PATCH_DIST_STRIP=	-p1

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

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
