# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	bmake
PORTVERSION=	20200318
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/sjg/

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Portable version of NetBSD 'make' utility

LICENSE=	BSD3CLAUSE

PORTSCOUT=	skipv:200910007

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	CONFIG_SITE=${CONFIG_SITE}

post-patch:	.SILENT
	${REINPLACE_CMD} 's/^\.Nx/NetBSD/' ${WRKDIR}/bmake/bmake.1

do-build:
	${SETENV} ${MAKE_ENV} ${SH} ${WRKDIR}/bmake/boot-strap \
		--with-default-sys-path='.../share/mk:${PREFIX}/share/mk' \
		-m ${WRKDIR}/mk objdir=${WRKDIR}/obj prefix=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/obj/bmake ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/bmake/bmake.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${SH} ${WRKSRC}/mk/install-mk -v ${STAGEDIR}${PREFIX}/share/mk
	${CHMOD} -x ${STAGEDIR}${PREFIX}/share/mk/meta2deps.py
	cd ${STAGEDIR}${PREFIX} ;					\
	    ${FIND} share/mk -type f -o -type l				\
		| ${SORT}						\
		>${WRKDIR}/PLIST.share-mk
	${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.share-mk"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.share-mk"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-share-mk
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.mk>
