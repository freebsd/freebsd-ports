# New ports collection makefile for:	kpcal
# Date created:		1 February 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	kpcal
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	yoichi
DISTNAME=	${PORTNAME}-${PORTVERSION}

PATCH_SITES=	http://www.tamaru.kuee.kyoto-u.ac.jp/~tsuchiya/misc/kpcal/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-HappyMonday2003.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Make Calendar in Postscript format

USE_REINPLACE=	yes
ALL_TARGET=	kpcal
MAN1=		kpcal.1
PLIST_FILES=	bin/kpcal

post-patch:
	${REINPLACE_CMD} -e 's/long/time_t/' ${WRKSRC}/kpcal.c
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kpcal ${LOCALBASE}/bin
	${INSTALL_MAN} ${WRKSRC}/kpcal.1 ${LOCALBASE}/man/man1

.include <bsd.port.mk>
