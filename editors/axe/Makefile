# Created by: John Capo <jc@irbs.com>
# $FreeBSD$

PORTNAME=	aXe
PORTVERSION=	6.1.2
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple to use text editor for X

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
ALL_TARGET=	Xaw3d all
MAN1=		axe.1 axinfo.1
MAKE_JOBS_UNSAFE=	yes
CFLAGS=		-Wno-return-type

NO_STAGE=	yes
.include <bsd.port.mk>
