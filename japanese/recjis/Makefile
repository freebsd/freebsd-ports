# New ports collection makefile for:   recjis
# Date created:        05 February 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	recjis
PORTVERSION=	1.0
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.leo.chubu.ac.jp/pub/tools/
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for recovery of broken japanese text

NO_WRKSUBDIR=	yes
ALL_TARGET=	prog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/*jis ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/recjis
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m 644 \
		${WRKSRC}/*_tbl ${PREFIX}/lib/recjis

.include <bsd.port.mk>
