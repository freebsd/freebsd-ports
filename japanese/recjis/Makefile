# New ports collection makefile for:   recjis
# Version required:    1.0
# Date created:        05 February 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1997/09/14 21:35:52 max Exp $
#

DISTNAME=	recjis-1.0
PKGNAME=	ja-recjis-1.0
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.leo.chubu.ac.jp/pub/tools/
DISTFILES=	recjis.tar.gz

MAINTAINER=	nacai@iname.com

NO_WRKSUBDIR=	yes
ALL_TARGET=	prog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/*jis ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/recjis
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m 777 \
		${WRKSRC}/*_tbl ${PREFIX}/lib/recjis

.include <bsd.port.mk>
