PORTNAME=	icc-profiles-openicc
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/openicc/OpenICC-Profiles

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Color data for color managed applications

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING    # Has a Copyright note

USES=		shared-mime-info tar:bzip2
GNU_CONFIGURE=	yes

SYSCOLORDIR=	share/color
PLIST_SUB=	SYSCOLORDIR=${SYSCOLORDIR}

.include <bsd.port.mk>
