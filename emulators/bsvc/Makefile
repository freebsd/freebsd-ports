# New ports collection Makefile for:	bsvc
# Version required:	2.0
# Date released:	03-Mar-1997
# Whom			tenser
#
# $Id: Makefile,v 1.3 1997/03/07 08:05:09 tg Exp $
#

DISTNAME=	bsvc-2.0
CATEGORIES=	emulators tk41
MASTER_SITES=	ftp://ftp.ncsu.edu/pub/eos/pub/bsvc/distribution/
EXTRACT_SUFX=	-src.tar.z

MAINTAINER=	tenser@spitfire.ecsel.psu.edu

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41

WRKSRC=		${WRKDIR}/${DISTNAME}/src

WISH=		wish4.1

pre-patch:
	@awk ' \
	{ \
		if (/PROJECT_BASE/ && /AWK_CHANGE_ME/) { \
			print "! PROJECT_BASE='"${WRKDIR}/${DISTNAME}"'" \
		} else if (/INSTALL_DIR/ && /AWK_CHANGE_ME/) { \
			print "! INSTALL_DIR='"${PREFIX}/bin"'" \
		} else if (/LIB_DIR/ && /AWK_CHANGE_ME/) { \
			print "! LIB_DIR ='"${PREFIX}/lib/bsvc"'" \
		} else if (/WISH/ && /AWK_CHANGE_ME/) { \
			print "! WISH='"${WISH}"'" \
		} else { \
			print \
		} \
	}' < ${FILESDIR}/patch-aa.in > ${PATCHDIR}/patch-aa
	@awk ' \
	{ \
		if (/^## Makefile/) { \
			print "## Makefile.FreeBSD - System Dependent Makefile for FreeBSD" \
		} else { \
			print \
		} \
	}' < ${WRKSRC}/Makefile.ULTRIX > ${WRKSRC}/Makefile

pre-clean:
	${RM} -f ${PATCHDIR}/patch-aa

.include <bsd.port.mk>
