# New ports collection makefile for:	hugs
# Version required:	1.4
# Date created:		22 September 1997
# Whom:			Torsten Teg Grust (Torsten.Grust@uni-konstanz.de)
#
# $Id: Makefile,v 1.1.1.1 1997/11/24 00:10:18 fenner Exp $
#

DISTNAME=	hugs-January1998-source
PKGNAME=	hugs-1.4-01-1998
CATEGORIES=	lang
MASTER_SITES=	ftp://haskell.org/pub/haskell/hugs/January1998/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Torsten.Grust@uni-konstanz.de

WRKSRC=		${WRKDIR}/hugs/src

ALL_TARGET=	default

# how to install a directory
INSTALL_DIR=	${INSTALL} -d -o bin -g bin -m 755
# where the Hugs documentation (distribution) files live
HUGS_DOC=	${WRKSRC}/../docs

MAN1=		hugs.1

pre-configure:
	${MV} ${WRKSRC}/MkInstal.in ${WRKSRC}/MkInstal.in.orig
	${SED} -e "s#/bin/cp#${INSTALL_DATA}#" \
	       -e "s#unix/install-sh#${INSTALL_PROGRAM}#" \
	       -e 's#$$(INSTALL) -d#${INSTALL_DIR}#' \
	       < ${WRKSRC}/MkInstal.in.orig > ${WRKSRC}/MkInstal.in

post-install:
	${MV} ${HUGS_DOC}/hugs.1 ${HUGS_DOC}/hugs.1.orig
	${SED} -e "s#^\.ds LB .*#.ds LB ${PREFIX}/share/hugs#" \
	       -e "s#^\.ds BN .*#.ds BN ${PREFIX}/bin#" \
	       -e "s#Prelude\.hs#lib/&#" \
	       < ${HUGS_DOC}/hugs.1.orig > ${HUGS_DOC}/hugs.1
	${INSTALL_MAN} ${HUGS_DOC}/hugs.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${INSTALL_DIR} ${PREFIX}/share/doc/hugs
	${INSTALL_DATA} ${HUGS_DOC}/README ${PREFIX}/share/doc/hugs
	${INSTALL_DATA} ${HUGS_DOC}/*.html ${PREFIX}/share/doc/hugs
.for DOC in manual-html haskore-html libs-html report library tutorial
	${INSTALL_DIR} ${PREFIX}/share/doc/hugs/${DOC}
	${INSTALL_DATA} ${HUGS_DOC}/${DOC}/* ${PREFIX}/share/doc/hugs/${DOC}
.endfor
.endif

.include <bsd.port.mk>
