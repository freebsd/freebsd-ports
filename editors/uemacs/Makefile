# Created by: tg
# $FreeBSD$

PORTNAME=	uemacs
PORTVERSION=	4.0
CATEGORIES=	editors
MASTER_SITES=	http://dl.ozzmosis.com/uemacs/
DISTNAME=	ue400dev

MAINTAINER=	mail@ozzmosis.com
COMMENT=	Full screen editor

NO_CDROM=	Resale allowed for media cost only

NO_STAGE=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-Laq

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
