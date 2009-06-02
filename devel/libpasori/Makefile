# New ports collection makefile for:	libpasori
# Date created:				18 January 2007
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$

PORTNAME=	libpasori
PORTVERSION=	02
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/20457
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	sarumaru@jp.FreeBSD.org
COMMENT=	FeliCa read/write library for Sony RC-S320 USB FeliCa R/W(PaSoRi)

USE_BZIP2=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/lib ${WRKSRC}/lpdump ${WRKSRC}/lptest
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/lib/Makefile
	@${CP} ${FILESDIR}/Makefile.lpdump ${WRKSRC}/lptest/Makefile
	@${CP} ${FILESDIR}/Makefile.lptest ${WRKSRC}/lpdump/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
