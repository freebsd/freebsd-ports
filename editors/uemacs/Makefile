# New ports collection makefile for:	MicroEmacs
# Date created:         16 Jan 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uemacs
PORTVERSION=	4.0
CATEGORIES=	editors
MASTER_SITES=	http://uemacs.tripod.com/ \
		ftp://aquest.com/pub/uemacs400/disk2/
DISTNAME=	ue400dev

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full screen editor

NO_CDROM=	"Resale allowed for media cost only"

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-Laq

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
