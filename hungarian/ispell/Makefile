# New ports collection makefile for:    magyarispell
# Date created:         20.03.2002
# Whom:                 mohacsi
#
# $FreeBSD$
#

PORTNAME=	ispell
PORTVERSION=    0.85
CATEGORIES=	hungarian textproc
MASTER_SITES=   http://www.szofi.hu/gnu/magyarispell/
DISTNAME=	magyarispell-${PORTVERSION}

MAINTAINER=	Janos.Mohacsi@bsd.hu

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

USE_GMAKE=      yes

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} magyar.hash magyar.dict magyar.aff \
		${PREFIX}/share/ispell
	${INSTALL_SCRIPT} ${FILESDIR}/ispell-hu.sh ${PREFIX}/bin/ispell-hu
	${MKDIR} ${PREFIX}/share/doc/hu-ispell
	${INSTALL_MAN} ${WRKSRC}/OLVASSEL ${WRKSRC}/README ${PREFIX}/share/doc/hu-ispell

.include <bsd.port.mk>
