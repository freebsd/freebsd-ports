# New ports collection makefile for:	xbms
# Date created:				Sun Apr 20 18:28:16 CEST 2003
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	extract-xiso
PORTVERSION=	1.4
CATEGORIES=	emulators
MASTER_SITES=	http://dwl.xbox-scene.net/~xbox/xbox-scene/tools/isotools/
PKGNAMESUFFIX=	-freebsd_v${PORTVERSION}
DISTNAME=       ${PORTNAME}${PKGNAMESUFFIX}
EXTRACT_SUFX=   .zip

MAINTAINER=	king@v2project.com
COMMENT=	This tool will extract files form  xdvdfs (xbox iso) image

PLIST_FILES=	bin/extract-xiso
WRKSRC=		${WRKDIR}/freebsd
NO_BUILD=       yes
USE_ZIP=        yes

ONLY_FOR_ARCHS=	i386

do-install:
	${CP} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.include <bsd.port.mk>
