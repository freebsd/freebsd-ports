# New ports collection makefile for:	hugs
# Date created:		22 September 1997
# Whom:			Torsten Teg Grust (Torsten.Grust@uni-konstanz.de)
#
# $FreeBSD$
#

PORTNAME=	hugs98
PORTVERSION=	200112
CATEGORIES=	lang
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/
DISTNAME=	${PORTNAME}-${HUGS_DATE}

MAINTAINER=	obraun@FreeBSD.org

WRKSRC=		${WRKDIR}/hugs98-${HUGS_DATE}/src

ALL_TARGET=	default

# how to install a directory
INSTALL_DIR=	${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 755
# where the Hugs documentation (distribution) files live
HUGS_DOC=	${WRKDIR}/hugs98-${HUGS_DATE}/docs
# Little hack to teach it to use our install
MAKE_ENV+=	HACK_INSTALL_DIR="${INSTALL_DIR}"
HUGS_DATE=	Dec2001

MAN1=		hugs.1

post-install:
	${SED} -e "s#Prelude\.hs#lib/&#" \
	       -e "s#^\.ds LB .*#.ds LB ${PREFIX}/share/hugs#" \
	       -e "s#^\.ds BN .*#.ds BN ${PREFIX}/bin#" \
	       < ${HUGS_DOC}/hugs.1 > ${HUGS_DOC}/hugs.1.fix
	${INSTALL_MAN} ${HUGS_DOC}/hugs.1.fix ${PREFIX}/man/man1/${MAN1}
	${RM} ${HUGS_DOC}/hugs.1.fix
.if !defined(NOPORTDOCS)
	${INSTALL_DIR} -d ${PREFIX}/share/doc/hugs
	${INSTALL_DATA} ${HUGS_DOC}/* ${PREFIX}/share/doc/hugs
	${INSTALL_DATA} ${WRKSRC}/../Credits ${PREFIX}/share/doc/hugs
	${INSTALL_DATA} ${WRKSRC}/../License ${PREFIX}/share/doc/hugs
	${INSTALL_DATA} ${WRKSRC}/../Readme ${PREFIX}/share/doc/hugs
.endif

.include <bsd.port.mk>
