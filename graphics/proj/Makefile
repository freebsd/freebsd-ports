# New ports collection makefile for:	proj
# Date created:				15 November 2001
# Whom:					jedgar@FreeBSD.org
#
# $FreeBSD$

PORTNAME=       proj
PORTVERSION=	4.4.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${NADFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Cartographic Projections library

NADFILES=	proj-nad27-1.1.tar.gz

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=		cs2cs.1 geod.1 nad2nad.1 proj.1
MAN3=		pj_init.3

post-extract:
.for file in ${NADFILES}
	@cd ${WRKSRC}/nad && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${file} ${EXTRACT_AFTER_ARGS}
.endfor

.include <bsd.port.mk>
