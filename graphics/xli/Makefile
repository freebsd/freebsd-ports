# New ports collection makefile for:	xli
# Version required:	1.16
# Date created:		24 November 1994
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	xli.1.16
PKGNAME=	xli-1.16
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		http://pantransit.reptiles.org/prog/
MASTER_SITE_SUBDIR=	applications
DISTFILES=	xli.1.16.tar.gz xli-png.tar.gz

MAINTAINER=	jkoshy@FreeBSD.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

USE_IMAKE=	yes
MAN1=		xli.1 xlito.1

NO_WRKSUBDIR=	yes

post-patch:
	@${ECHO_MSG} "===>  Applying png patch for ${PKGNAME}"
	@${SED} -e 's/^--- xli/--- ./' ${WRKSRC}/png.patch | ${PATCH} ${PATCH_ARGS}

.include <bsd.port.mk>
