# New ports collection makefile for:   gnucash-doc
# Date created:        Sun Feb 16 2003
# Whom:                Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#    $MCom: ports/finance/gnucash-docs/Makefile,v 1.3 2006/12/24 19:09:22 ahze Exp $

PORTNAME=	gnucash-docs
PORTVERSION=	2.0.1
CATEGORIES=	finance gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.gnucash.org/pub/gnucash/sources/stable/ \
		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/
MASTER_SITE_SUBDIR=	gnucash

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Documentation for gnucash

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper \
		yelp:${PORTSDIR}/x11/yelp

INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2 gnomehier
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's| $$(datadir)/omf| ${PREFIX}/share/gnome/omf|'

.include <bsd.port.mk>
