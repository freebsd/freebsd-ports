# New ports collection makefile for:	a2png
# Date created:		07 Oct 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	a2png
PORTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts plain ASCII text into PNG bitmap images

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gd
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
