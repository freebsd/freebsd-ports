# New ports collection makefile for:	electric
# Date created:		4 May 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	electric
PORTVERSION=	7.0.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^(...)\./\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Sophisticated electrical CAD system

USE_MOTIF=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/electric/lib/|${DATADIR}/lib/|; \
		s|/usr/share/electric/doc/|${DOCSDIR}/|; \
		s|/usr/bin/|${LOCALBASE}/bin/|; \
		s|${LOCALBASE}/bin/sort|${SORT}|' \
		${WRKSRC}/src/include/config.h
	@${REINPLACE_CMD} -e 's|/usr/share/electric/lib|${DATADIR}/lib|; \
		s|/usr/share/electric/doc|${DOCSDIR}|; \
		s|@PTHREAD_LIBS@|${PTHREAD_LIBS:S/"//g}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6/|${X11BASE}/|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${PREFIX}/bin/electric

.include <bsd.port.mk>
