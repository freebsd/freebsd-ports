# New ports collection makefile for:	uisp
# Date created:		17 Feb 2001
# Whom:			Bruno Schwander<bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	uisp
PORTVERSION=	1.0b
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://medo.fov.uni-mb.si/mapp/uTools/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A versatile programmer for atmel AVR microcontrollers

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_REINPLACE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s@-O3@${CFLAGS}@g; \
			s@g\+\+@${CXX}@g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
