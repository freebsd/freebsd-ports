# New ports collection makefile for:   gnucash-doc
# Date created:        Sun Feb 16 2003
# Whom:                Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#

PORTNAME=	gnucash-docs
PORTVERSION=	1.8.1
CATEGORIES=	finance gnome
MASTER_SITES=	http://www.gnucash.org/pub/gnucash/sources/stable/ \
		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnucash

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documentation for gnucash

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper \
		${LOCALBASE}/include/db4/db_185.h:${PORTSDIR}/databases/db4
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
# XXX Note, this is a hack.  When DocBook 4.1.2 has been merged into the
# system XML catalog file, this line should be removed.
MAKE_ENV=	XML_CATALOG_FILES="${LOCALBASE}/share/sk/catalog ${LOCALBASE}/share/sk/docbook/catalog"

.include <bsd.port.mk>
