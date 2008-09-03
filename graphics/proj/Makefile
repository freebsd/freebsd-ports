# New ports collection makefile for:	proj
# Date created:				15 November 2001
# Whom:					jedgar@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	proj
PORTVERSION=	4.6.1
CATEGORIES=	graphics geography
MASTER_SITES=	ftp://ftp.remotesensing.org/proj/ \
		http://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATUM_GRID_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Cartographic Projections library

DATUM_GRID_FILES=	proj-datumgrid-1.4.tar.gz

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		cs2cs.1 geod.1 nad2nad.1 proj.1
MAN3=		pj_init.3

post-extract:
	@${TAR} -xof ${DISTDIR}/${DATUM_GRID_FILES} -C ${WRKSRC}/nad

.include <bsd.port.mk>
