# Created by: db
# $FreeBSD$

PORTNAME=	nec2c
PORTVERSION=	.9
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://ftp-mirror.internap.com/pub/FreeBSD/distfiles/nec2c/ \
		http://ftp.cerias.purdue.edu/pub/os/FreeBSD/distfiles/nec2c/
DISTNAME=	nec2c

MAINTAINER=	db@FreeBSD.org
COMMENT=	Used to calculate antenna patterns useful to ham radio

LIB_DEPENDS=	libccm.so:${PORTSDIR}/math/ccmath

post-patch:
	${CP} ${FILESDIR}/carg.c  ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nec2c ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Input/*.nec ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Input/*.NEC ${STAGEDIR}${EXAMPLESDIR}
.include <bsd.port.mk>
