# Created by: tg
# $FreeBSD$

PORTNAME=	uemacs
PORTVERSION=	4.0
CATEGORIES=	editors
MASTER_SITES=	http://ozzmosis.com/uemacs/
DISTNAME=	ue400dev

MAINTAINER=	mail@ozzmosis.com
COMMENT=	A full screen editor

NO_CDROM=	Resale allowed for media cost only

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-Laq

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
