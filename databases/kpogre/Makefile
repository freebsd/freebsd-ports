# New ports collection makefile for:	kpogre
# Date created:		2008-06-04
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kpogre
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	databases kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	PostgreSQL administration tool for KDE

BUILD_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx
RUN_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx

USE_KDELIBS_VER=	3
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PGSQL=	yes

post-patch:
	${REINPLACE_CMD} -e '/kde_appsdir/s|applnk||g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '/kde_appsdir/s|Applications|applications/kde|g' \
		-e '/kde_appsdir/s|share/||g' ${WRKSRC}/${PORTNAME}/Makefile.in

.include <bsd.port.mk>
