# New ports collection makefile for:   gnucash-doc
# Date created:        Sun Feb 16 2003
# Whom:                Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#   $MCom: ports/finance/gnucash-docs/Makefile,v 1.7 2007/08/04 03:51:29 marcus Exp $
#

PORTNAME=	gnucash-docs
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	finance gnome
MASTER_SITES=	SF/gnucash/${PORTNAME}/${PORTVERSION} \
		http://www.gnucash.org/pub/gnucash/sources/stable/ \
		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Documentation for gnucash

LIB_DEPENDS=	rarian.0:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2 gnomehier
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

.include <bsd.port.mk>
