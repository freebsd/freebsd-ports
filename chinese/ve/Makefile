# New ports collection makefile for:	ve
# Date created:		25 Aug 1999
# Whom:			Ching-Hong Wu <woju@freebsd.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ve
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.ntu.edu.tw/FreeBSD/woju/source/ \
		ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NTHU-CS Maple BBS 2.36 BBS-like editor

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
EXTRA_PATCHES=	${FILESDIR}/extrapatch-screen.c
.endif

.include <bsd.port.post.mk>
