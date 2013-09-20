# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	kpcal
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	yoichi

PATCH_SITES=	http://www.tamaru.kuee.kyoto-u.ac.jp/~tsuchiya/misc/kpcal/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-20040518.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make Calendar in Postscript format

ALL_TARGET=	kpcal
MAN1=		kpcal.1
PLIST_FILES=	bin/kpcal

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's/long/time_t/' ${WRKSRC}/kpcal.c
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kpcal ${LOCALBASE}/bin
	${INSTALL_MAN} ${WRKSRC}/kpcal.1 ${LOCALBASE}/man/man1

.include <bsd.port.mk>
