# New ports collection makefile for:	xfractint
# Date created:		7 Sept 1995
# Whom:			cacho@mexicano.gdl.iteso.mx
#
# $FreeBSD$
#

PORTNAME=	xfractint
PORTVERSION=	3.10
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.phoenix.net/pub/USERS/twegner/ \
		http://spanky.triumf.ca/pub/fractals/programs/unix/
DISTNAME=	xfrac310

MAINTAINER=	ports@FreeBSD.org

USE_ZIP=	yes
USE_XLIB=	yes
NO_WRKSUBDIR=	yes
MAN1=		xfractint.1

pre-patch:
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${PERL} -pi -e \
		's|malloc.h|stdlib.h|'

.include <bsd.port.mk>
