# New ports collection makefile for:	hugs
# Version required:	1.4 (January 1998)
# Date created:		22 September 1997
# Whom:			Torsten Teg Grust (Torsten.Grust@uni-konstanz.de)
#
# $Id: Makefile,v 1.4 1998/02/17 21:32:18 steve Exp $
#

DISTNAME=	hugs-June98-source
PKGNAME=	hugs-1.4
CATEGORIES=	lang
MASTER_SITES=	ftp://haskell.org/pub/haskell/hugs/LATEST/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Torsten.Grust@uni-konstanz.de

WRKSRC=		${WRKDIR}/hugs/src

ALL_TARGET=	default

# how to install a directory
INSTALL_DIR=	${INSTALL} -d -o bin -g bin -m 755
# where the Hugs documentation (distribution) files live
HUGS_DOC=	${WRKSRC}/../docs

MAN1=		hugs.1

post-install:
	${SED} -e "s#Prelude\.hs#lib/&#" \
	       -e "s#^\.ds LB .*#.ds LB ${PREFIX}/share/hugs#" \
	       -e "s#^\.ds BN .*#.ds BN ${PREFIX}/bin#" \
	       < ${HUGS_DOC}/hugs.1 > ${HUGS_DOC}/hugs.1.fix
	${INSTALL_MAN} ${HUGS_DOC}/hugs.1.fix ${PREFIX}/man/man1/${MAN1}
	${RM} ${HUGS_DOC}/hugs.1.fix
	# fix owner/permissions
	find ${PREFIX}/share/hugs -type d | xargs chmod 755
	find ${PREFIX}/share/hugs -type f | xargs chmod ${SHAREMODE}
	find ${PREFIX}/share/hugs         | xargs chown ${SHAREOWN}.${SHAREGRP}
.if !defined(NOPORTDOCS)
	${INSTALL_DIR} ${PREFIX}/share/doc/hugs
	${CP} -R ${HUGS_DOC}/* ${PREFIX}/share/doc/hugs
	# fix owner/permissions
	find ${PREFIX}/share/doc/hugs -type d | xargs chmod 755
	find ${PREFIX}/share/doc/hugs -type f | xargs chmod ${SHAREMODE}
	find ${PREFIX}/share/doc/hugs         | xargs chown ${SHAREOWN}.${SHAREGRP}
.endif

.include <bsd.port.mk>
