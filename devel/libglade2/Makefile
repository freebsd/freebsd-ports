# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$
#   $MCom: ports/devel/libglade2/Makefile,v 1.26 2007/08/01 16:13:48 mezz Exp $

PORTNAME=	libglade2
PORTVERSION=	2.6.4
PORTREVISION?=	8
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME/sources/${PORTNAME:S/2$//}/${PORTVERSION:C/..$//}
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME glade library

USES=		tar:bzip2

.if !defined(REFERENCE_PORT)

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

GNU_CONFIGURE=	yes
USES+=		gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	libxml2 gtk20 referencehack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc \
		--with-xml-catalog=${LOCALBASE}/share/xml/catalog.ports
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	XMLCATALOG="${LOCALBASE}/bin/xmlcatalog" \
		CATALOG_PORTS_XML="${LOCALBASE}/share/xml/catalog.ports"

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python:2
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "

post-patch:
	@${REINPLACE_CMD} -E 's/in (python.*)+ none/in none/' \
		${WRKSRC}/configure
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libglade/2.0

.include <bsd.port.mk>

.endif
