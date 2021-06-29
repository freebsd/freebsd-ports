# Created by: Glenn Johnson <glennpj@charter.net>
#   $MCom: ports/finance/gnucash-docs/Makefile,v 1.7 2007/08/04 03:51:29 marcus Exp $

PORTNAME=	gnucash-docs
DISTVERSION=	4.6
CATEGORIES=	finance gnome
MASTER_SITES=	SF/gnucash/gnucash%20%28stable%29/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Documentation for gnucash

LIB_DEPENDS=	librarian.so:textproc/rarian
RUN_DEPENDS=	yelp:x11/yelp

USES=		autoreconf localbase gmake gnome
USE_GNOME=	libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/scrollkeeper-preinstall/s|$$(docdir)|$$(gnomehelpdir)|' \
		${WRKSRC}/omf.make ${WRKSRC}/guide/C/Makefile.in ${WRKSRC}/guide/de/Makefile.in \
		${WRKSRC}/guide/it/Makefile.in ${WRKSRC}/guide/ja/Makefile.in \
		${WRKSRC}/help/C/Makefile.in ${WRKSRC}/help/de/Makefile.in \
		${WRKSRC}/help/it/Makefile.in

.include <bsd.port.mk>
