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
DISTNAME=	Hugs98-Sep1999

MAINTAINER=	Torsten.Grust@uni-konstanz.de

WRKSRC=		${WRKDIR}/hugs98/src

ALL_TARGET=	default

# how to install a directory
INSTALL_DIR=	${INSTALL} -d -o bin -g bin -m 755
# where the Hugs documentation (distribution) files live
HUGS_DOC=	${WRKDIR}/hugs98/docs

MAN1=		hugs.1

post-install:
	strip ${PREFIX}/bin/hugs
	strip ${PREFIX}/bin/runhugs
	${SED} -e "s#Prelude\.hs#lib/&#" \
	       -e "s#^\.ds LB .*#.ds LB ${PREFIX}/share/hugs#" \
	       -e "s#^\.ds BN .*#.ds BN ${PREFIX}/bin#" \
	       < ${HUGS_DOC}/hugs.1 > ${HUGS_DOC}/hugs.1.fix
	${INSTALL_MAN} ${HUGS_DOC}/hugs.1.fix ${PREFIX}/man/man1/${MAN1}
	${RM} ${HUGS_DOC}/hugs.1.fix
	# fix owner/permissions
	find ${PREFIX}/share/hugs -type d | xargs ${CHMOD} 755
	find ${PREFIX}/share/hugs -type f | xargs ${CHMOD} ${SHAREMODE}
	find ${PREFIX}/share/hugs         | xargs ${CHOWN} ${SHAREOWN}.${SHAREGRP}
.if !defined(NOPORTDOCS)
	${INSTALL_DIR} ${PREFIX}/share/doc/hugs
	${CP} -R ${HUGS_DOC}/* ${PREFIX}/share/doc/hugs
	# fix owner/permissions
	find ${PREFIX}/share/doc/hugs -type d | xargs ${CHMOD} 755
	find ${PREFIX}/share/doc/hugs -type f | xargs ${CHMOD} ${SHAREMODE}
	find ${PREFIX}/share/doc/hugs         | xargs ${CHOWN} ${SHAREOWN}.${SHAREGRP}
.endif

.include <bsd.port.mk>
