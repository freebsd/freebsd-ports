# New ports collection Makefile for:	bsvc
# Version required:	2.0
# Date created:		03-Mar-1997
# Whom:			tenser
#
# $FreeBSD$
#

DISTNAME=	bsvc-2.0
CATEGORIES=	emulators tk41
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/emulators
EXTRACT_SUFX=	-src.tar.z

MAINTAINER=	tenser@spitfire.ecsel.psu.edu

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11-toolkits/tk41

WRKSRC=		${WRKDIR}/${DISTNAME}/src

WISH=		wish4.1

pre-patch:
	@${AWK} ' \
	{ \
		if (/^## Makefile/) { \
			print "## Makefile.FreeBSD - System Dependent Makefile for FreeBSD" \
		} else { \
			print \
		} \
	}' < ${WRKSRC}/Makefile.ULTRIX > ${WRKSRC}/Makefile

post-patch:
	@${AWK} ' \
	{ \
		if (/PROJECT_BASE/ && /AWK_CHANGE_ME/) { \
			print "PROJECT_BASE='"${WRKDIR}/${DISTNAME}"'" \
		} else if (/INSTALL_DIR/ && /AWK_CHANGE_ME/) { \
			print "INSTALL_DIR='"${PREFIX}/bin"'" \
		} else if (/LIB_DIR/ && /AWK_CHANGE_ME/) { \
			print "LIB_DIR ='"${PREFIX}/lib/bsvc"'" \
		} else if (/WISH/ && /AWK_CHANGE_ME/) { \
			print "WISH='"${WISH}"'" \
		} else { \
			print \
		} \
	}' < ${WRKSRC}/Makefile.common > ${WRKSRC}/Makefile.common.tmp
	@${MV} -f ${WRKSRC}/Makefile.common.tmp ${WRKSRC}/Makefile.common

.include <bsd.port.mk>
