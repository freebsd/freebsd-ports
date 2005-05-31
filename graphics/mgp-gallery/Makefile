# ex:ts=8
#
# New ports collection makefile for:	mgp-gallery
# Date created:		2002-12-28
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	mgp-gallery
PORTVERSION=	2.0
PORTREVISION=	2
PORTEPOCH=	0
CATEGORIES=	graphics
MASTER_SITES=	http://puchol.com/cpg/software/mgp/
DISTFILES=	mgp-midgard-${PORTVERSION}.tgz \
		mgp-backgrounds-${PORTVERSION}.tgz \
		mgp-solid-${PORTVERSION}.tgz \
		mgp-gradients-${PORTVERSION}.tgz
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

DEPRECATED=	"no longer available from master site"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of various templates for magicpoint

NO_BUILD=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

PKGDATA_SUBDIR=		lib/X11/mgp
PKGDATADIR=		${PREFIX}/${PKGDATA_SUBDIR}

do-install:
	${MKDIR} ${PKGDATADIR}
.for i in midgard backgrounds solid gradients
	${MKDIR} ${PKGDATADIR}/${i}
	cd ${WRKDIR}/mgp-${i}-${PORTVERSION};\
	${INSTALL_DATA} * ${PKGDATADIR}/${i};\
	${SCRIPTDIR}/fix-gallery "${INSTALL_DATA}" ${PKGDATADIR}/${i} *.mgp
.endfor # i in midgard backgrounds solid gradient

.include <bsd.port.post.mk>
