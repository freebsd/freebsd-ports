# ex:ts=8
#
# New ports collection makefile for:	kaptain
# Date created:			2002-12-12
# Whom:				Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kaptain
PORTVERSION=	0.72
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for building/running QT GUIs for command line programs

USE_XORG=	x11 ice xext
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mt

MAN1=		kaptain.1
INFO=		kaptain

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/examples/dia2code.kaptn

.include <bsd.port.mk>
