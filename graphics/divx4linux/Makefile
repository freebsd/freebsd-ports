# New ports collection makefile for:	divx4linux
# Date created:				Mon Sep 24 15:40:14 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	divx4linux
PORTVERSION=	0.${RELEASE_DATE}
CATEGORIES=	graphics linux
MASTER_SITES=	http://download.divx.com/videocodecs/linux/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org

RESTRICTED=	unsure of licensing issues

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
WRKSRC=	${WRKDIR}/${DISTNAME:C/_.+$//}
NO_BUILD=	yes
PLIST_SUB=	PKGNAME="${PKGNAME}"

RELEASE_DATE=	20011010_4.02

post-patch:
.for ext in h linux txt
	@${PERL} -pi -e "s///" ${WRKSRC}/*.${ext}
.endfor

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/usr/doc/${PKGNAME}
.for ext in linux txt
	@${INSTALL_DATA} ${WRKSRC}/*.${ext} ${PREFIX}/usr/doc/${PKGNAME}
.endfor
.endif
# Header file installation
	@${MKDIR} ${PREFIX}/usr/include/divx
	@${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/usr/include/divx
# Library installation
	@${INSTALL_DATA} ${WRKSRC}/*.so ${PREFIX}/usr/lib
	@${LINUXBASE}/sbin/ldconfig

.include <bsd.port.mk>
