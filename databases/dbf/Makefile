# ex:ts=8
# Ports collection makefile for:	dbf
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbf
PORTVERSION=	0.8
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show and convert the content of dBASE III, IV, and 5.0 files

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_REINPLACE=	yes

post-patch:
.for file in endian.h tables.h
	@${REINPLACE_CMD} -e '/typedef u_int/d' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbf ${PREFIX}/bin

.include <bsd.port.mk>
