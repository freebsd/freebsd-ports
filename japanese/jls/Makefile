# New ports collection makefile for:	jls
# Date created:		4 January 1999
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	ls
PORTVERSION=	0.5
CATEGORIES=	japanese
MASTER_SITES=	http://www.angels.vg/bsd/
DISTNAME=	freebsd-ls.releng_4_9_0_release

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	j${PORTNAME}-${PORTVERSION}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kazami@angels.vg
COMMENT=	Japanized ls

MAN1=		jls.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/jls

WRKSRC=	${WRKDIR}/ls

pre-patch:
	cd ${WRKSRC}; ${MV} ls.1 jls.1

.include <bsd.port.mk>
