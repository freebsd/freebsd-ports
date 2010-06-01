# New ports collection makefile for:    magyarispell
# Date created:         20.03.2002
# Whom:                 mohacsi
#
# $FreeBSD$
#

PORTNAME=	ispell
PORTVERSION=	1.6.1
CATEGORIES=	hungarian textproc
#MASTER_SITES=	http://www.szofi.hu/gnu/magyarispell/
MASTER_SITES=	SF/magyar${PORTNAME}/Magyar%20Ispell/${PORTVERSION}
DISTNAME=	magyarispell-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Hungarian dictionary for ispell

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

USE_GMAKE=	yes
DOCSDIR=	${PREFIX}/share/doc/hu-ispell
DOCS=		OLVASSEL README GYIK ChangeLog

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tmp/magyar4ispell.hash ${DATADIR}/magyar.hash
	${INSTALL_DATA} ${WRKSRC}/tmp/magyar4ispell.dict ${DATADIR}/magyar.dict
	${INSTALL_DATA} ${WRKSRC}/tmp/magyar.aff ${DATADIR}
	${LN} -sf ${DATADIR}/magyar.hash ${DATADIR}/hungarian.hash
	${INSTALL_SCRIPT} ${FILESDIR}/ispell-hu.sh ${PREFIX}/bin/ispell-hu
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
