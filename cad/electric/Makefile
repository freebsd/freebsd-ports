# New ports collection makefile for:	electric
# Date created:		4 May 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	electric
PORTVERSION=	6.0.7.1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^(...)\./\1/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Sophisticated electrical CAD system

USE_REINPLACE=	yes
USE_SIZE=	yes
USE_XLIB=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-with-x
WRKSRC=	${WRKDIR}/electric-6.07

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/lib/electric/|${PREFIX}/share/electric/lib/|; \
		s|/usr/local/|${PREFIX}/|' ${WRKSRC}/src/include/config.h
	@${REINPLACE_CMD} -e 's|/lib/electric|/share/electric/lib|; \
		s|@PTHREAD_LIBS@|${PTHREAD_LIBS:S/"//g}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6/|${X11BASE}/|' ${WRKSRC}/configure

.include <bsd.port.mk>
