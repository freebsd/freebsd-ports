# New ports collection makefile for:	t_coffee
# Date created:		27 June 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	t_coffee
PORTVERSION=	1.37
CATEGORIES=	biology
MASTER_SITES=	http://igs-server.cnrs-mrs.fr/~cnotred/Packages/
DISTNAME=	T-COFFEE_distribution

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	clustalw:${PORTSDIR}/biology/clustalw
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}_Version_${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/t_coffee_source
MAKE_ENV=	MV=${MV} USER_BIN=${LOCALBASE}/bin \
	  	CLUSTALW_4_TCOFFEE=${LOCALBASE}/bin/clustalw
MAKEFILE=	makefile
PKGMESSAGE=	${WRKDIR}/pkg-message

post-build:
	@ cd ${WRKSRC}/lalign && ${SETENV} ${MAKE_ENV} ${MAKE} \
	  ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

.include <bsd.port.pre.mk>

do-install:
.for binfile in t_coffee_source/t_coffee lalign/lalign2list
	@ ${INSTALL_PROGRAM} ${WRKSRC}/${binfile} ${PREFIX}/bin
.endfor
.for scriptfile in extract_from_pdb mocca
	@ ${INSTALL_SCRIPT} ${WRKSRC}/bin/${scriptfile} ${PREFIX}/bin
.endfor

post-install:
	@ ${MKDIR} ${DATADIR}
	@ ${INSTALL_DATA} ${WRKSRC}/html/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${RMDIR} ${WRKSRC}/example/aln 2>/dev/null || ${TRUE}
	@ cd ${WRKSRC}/example && find * \
	  | cpio --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@ ${SED} -e 's#%%DATADIR%%#${DATADIR}#' ${.CURDIR}/pkg-message \
	  > ${PKGMESSAGE}
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.endif
.include <bsd.port.post.mk>
