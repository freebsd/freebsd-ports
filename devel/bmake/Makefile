# New ports collection makefile for:	bmake
# Date created:				13 September 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bmake
PORTVERSION=	20111001
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/sjg/ \
		http://www.gtlib.cc.gatech.edu/pub/NetBSD/misc/sjg/ \
		ftp://ftp.uk.netbsd.org/pub/NetBSD/misc/sjg/ \
		ftp://ftp.de.netbsd.org/pub/NetBSD/misc/sjg/
DISTFILES=	bmake-${PORTVERSION}.tar.gz mk-${PORTVERSION}.tar.gz

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Portable version of NetBSD 'make' utility

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		bmake.1

post-patch:	.SILENT
	${REINPLACE_CMD} 's/^\.Nx/NetBSD/' ${WRKDIR}/bmake/bmake.1

do-build:
	${SETENV} ${MAKE_ENV} ${SH} ${WRKDIR}/bmake/boot-strap \
		-m ${WRKDIR}/mk objdir=${WRKDIR}/obj prefix=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/obj/bmake ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/bmake/bmake.1 ${MAN1PREFIX}/man/man1
	${SH} ${WRKDIR}/mk/install-mk ${PREFIX}/share/mk
	cd ${PREFIX} ;						\
	    ${FIND} share/mk -type f -o -type l			\
	    	| ${SORT}					\
	    	>${WRKDIR}/PLIST.share-mk
	cd ${PREFIX} ;						\
	    ${FIND} share/mk/${_DATADIR} -type d		\
	    	| ${SORT} -r | ${SED} -e 's/^/@dirrm /g'	\
		>>${WRKDIR}/PLIST.share-mk
	${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.share-mk"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.share-mk"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-share-mk
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.mk>
