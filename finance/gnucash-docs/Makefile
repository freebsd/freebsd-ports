# Created by: Glenn Johnson <glennpj@charter.net>
# $FreeBSD$
#   $MCom: ports/finance/gnucash-docs/Makefile,v 1.7 2007/08/04 03:51:29 marcus Exp $

PORTNAME=	gnucash-docs
PORTVERSION=	2.6.2
CATEGORIES=	finance gnome
MASTER_SITES=	SF/gnucash/${PORTNAME}/${PORTVERSION} \
		http://www.gnucash.org/pub/gnucash/sources/stable/ \
		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documentation for gnucash

LIB_DEPENDS=	librarian.so:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

INSTALLS_OMF=	yes
USES=		gmake
USE_GNOME=	libxml2 gnomehier
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e '/scrollkeeper-preinstall/s|$$(docdir)|$$(gnomehelpdir)|' \
		${WRKSRC}/omf.make ${WRKSRC}/guide/C/Makefile.in ${WRKSRC}/guide/de/Makefile.in \
		${WRKSRC}/guide/it/Makefile.in ${WRKSRC}/guide/ja/Makefile.in \
		${WRKSRC}/help/C/Makefile.in ${WRKSRC}/help/de/Makefile.in \
		${WRKSRC}/help/it/Makefile.in

.include <bsd.port.mk>
