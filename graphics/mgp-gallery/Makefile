# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	mgp-gallery
# Date created:		2002-12-28
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	mgp-gallery
PORTVERSION=	2.0
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	graphics
MASTER_SITES=	http://puchol.com/cpg/software/mgp/
DISTFILES=	mgp-midgard-${PORTVERSION}.tgz \
		mgp-backgrounds-${PORTVERSION}.tgz \
		mgp-solid-${PORTVERSION}.tgz \
		mgp-gradients-${PORTVERSION}.tgz
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	alane@FreeBSD.org

NO_BUILD=yes

.include <bsd.port.pre.mk>

DATA_SUBDIR=		share
DATADIR=		${PREFIX}/${DATA_SUBDIR}
PKGDATA_SUBDIR=		share/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PKGDATADIR=		${PREFIX}/${PKGDATA_SUBDIR}

PLIST=	${WRKDIR}/plist

post-extract:
	${TOUCH} ${PLIST}

do-install:
	${MKDIR} ${PKGDATADIR}
.for i in midgard backgrounds solid gradients
	${MKDIR} ${PKGDATADIR}/${i}
	cd ${WRKDIR}/mgp-${i}-${PORTVERSION};\
	${INSTALL_DATA} * ${PKGDATADIR}/${i}
.endfor # i in midgard backgrounds solid gradient
	cd ${PREFIX};\
	${RM} -f ${PLIST};\
	${FIND} ${PKGDATA_SUBDIR} -type f | sort >>${PLIST};\
	${FIND} ${PKGDATA_SUBDIR} -type d | sort -r \
		| ${SED} 's|^|@dirrm |' >>${PLIST}

.include <bsd.port.post.mk>

#EOF
