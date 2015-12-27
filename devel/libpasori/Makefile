# Created by: Yoshihiko Sarumaru <mistral@imasy.or.jp>
# $FreeBSD$

PORTNAME=	libpasori
PORTVERSION=	02
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SOURCEFORGE_JP/${PORTNAME}/20457
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FeliCa read/write library for Sony RC-S320 USB FeliCa R/W(PaSoRi)

USES=		tar:bzip2 uidfix
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/lib ${WRKSRC}/lpdump ${WRKSRC}/lptest
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.lib.usb20 ${WRKSRC}/lib/Makefile
	@${CP} ${FILESDIR}/Makefile.lpdump ${WRKSRC}/lpdump/Makefile
	@${CP} ${FILESDIR}/Makefile.lptest ${WRKSRC}/lptest/Makefile

.include <bsd.port.mk>
