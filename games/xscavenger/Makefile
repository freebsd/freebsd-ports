# Created by: eivind
# $FreeBSD$

PORTNAME=	xscavenger
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.xdr.com/dash/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lode Runner clone for X11

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../copyright

WRKSRC_SUBDIR=	src

USES=		imake tar:tgz
USE_XORG=	x11 xext

CFLAGS+=	-Wno-return-type -Wno-pointer-sign

pre-configure:
	@${LN} -sf scavenger.6 ${WRKSRC}/scavenger.man
	@${ECHO_CMD} "MANSUFFIX=6" >> ${WRKSRC}/Imakefile

.include <bsd.port.mk>
