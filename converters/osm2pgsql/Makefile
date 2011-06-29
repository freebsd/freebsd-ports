# New ports collection makefile for:	osm2pgsql
# Date created:		29 Jun 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osm2pgsql
PORTVERSION=	r26200
CATEGORIES=	converters geography
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OSM XML data to PostgreSQL database

LIB_DEPENDS=	proj.6:${PORTSDIR}/graphics/proj \
		geos.0:${PORTSDIR}/graphics/geos \
		protobuf-c.0:${PORTSDIR}/devel/protobuf-c

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf automake libtool aclocal autoheader libtoolize
USE_GMAKE=	yes
USE_PGSQL=	yes
USE_GNOME=	libxml2
MAKE_JOBS_SAFE=	yes

PORTDOCS=	ChangeLog README AUTHORS TODO

MAN1=		osm2pgsql.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/m4/*.m4

run-autotools:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./autogen.sh

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
