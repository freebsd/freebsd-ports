# New ports collection makefile for:	kpcal
# Date created:		1 February 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	kpcal
PORTVERSION=	2.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.eken.phys.nagoya-u.ac.jp/~yoichi/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}

PATCH_SITES= http://www.tamaru.kuee.kyoto-u.ac.jp/~tsuchiya/misc/
PATCHFILES= ${PORTNAME}-${PORTVERSION}-Shunbun.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

ALL_TARGET=	kpcal

post-configure:
	${GZIP_CMD} ${WRKSRC}/kpcal.1
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kpcal ${LOCALBASE}/bin
	${INSTALL_MAN} ${WRKSRC}/kpcal.1.gz ${LOCALBASE}/man/man1

.include <bsd.port.mk>
