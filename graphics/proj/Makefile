# New ports collection makefile for:	proj
# Date created:				15 November 2001
# Whom:					jedgar@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	proj
PORTVERSION=	4.6.0
CATEGORIES=	graphics geography
MASTER_SITES=	ftp://ftp.remotesensing.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATUM_GRID_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Cartographic Projections library

DATUM_GRID_FILES=	proj-datumgrid-1.3.tar.gz

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		cs2cs.1 geod.1 nad2nad.1 proj.1
MAN3=		pj_init.3

post-extract:
.for file in ${DATUM_GRID_FILES}
	@cd ${WRKSRC}/nad && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${file} ${EXTRACT_AFTER_ARGS}
.endfor

.include <bsd.port.mk>
