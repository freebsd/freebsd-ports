# New ports collection makefile for:	libglade2
# Date created:				18 August 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#   $MCom: ports/devel/libglade2/Makefile,v 1.26 2007/08/01 16:13:48 mezz Exp $
#

PORTNAME=	libglade2
PORTVERSION=	2.6.4
PORTREVISION?=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/${PORTVERSION:C/..$//}
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME glade library

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

RUN_DEPENDS=	xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack libxml2 gtk20 referencehack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc \
		--with-xml-catalog=${LOCALBASE}/share/xml/catalog.ports
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	XMLCATALOG="${LOCALBASE}/bin/xmlcatalog" \
		CATALOG_PORTS_XML="${LOCALBASE}/share/xml/catalog.ports"

OPTIONS=		PYTHON  "Use Python"    on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_PYTHON)
BUILD_DEPENDS+=	${PYEXPAT}
RUN_DEPENDS+=	${PYEXPAT}

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "

post-patch:
	@${REINPLACE_CMD} -E 's/in (python.*)+ none/in none/' \
		${WRKSRC}/configure
.endif

post-install:
	${MKDIR} ${PREFIX}/lib/libglade/2.0

.include <bsd.port.mk>

.endif
