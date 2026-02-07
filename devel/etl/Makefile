PORTNAME=	etl
PORTVERSION=	1.4.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel lang

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Voria Extended Class and Template Library
WWW=		https://www.synfig.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20

USES=		autoreconf gnome pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	synfig
GH_PROJECT=	synfig
USE_GNOME=	glib20 glibmm intltool

GNU_CONFIGURE=	yes

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
NO_ARCH=	yes
PORTSCOUT=	limitw:1,even

WRKSRC_SUBDIR=	ETL

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
