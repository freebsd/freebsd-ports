# New ports collection makefile for:	hugs
# Date created:		22 September 1997
# Whom:			Torsten Teg Grust (Torsten.Grust@uni-konstanz.de)
#
# $FreeBSD$
#

PORTNAME=	hugs
PORTVERSION=	98
CATEGORIES=	lang
MASTER_SITES=	ftp://www.cse.ogi.edu/pub/pacsoft/hugs/
DISTNAME=	${PORTNAME}${PORTVERSION}-${HUGS_DATE}

MAINTAINER=	Torsten.Grust@uni-konstanz.de

WRKSRC=		${WRKDIR}/hugs98/src

ALL_TARGET=	default

# how to install a directory
INSTALL_DIR=	${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 755
# where the Hugs documentation (distribution) files live
HUGS_DOC=	${WRKDIR}/hugs98/docs
# Little hack to teach it to use our install
MAKE_ENV+=	HACK_INSTALL_DIR="${INSTALL_DIR}"
HUGS_DATE=	Feb2000

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
.endif

.include <bsd.port.mk>
