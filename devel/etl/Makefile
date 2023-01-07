PORTNAME=	etl
PORTVERSION=	1.4.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel lang

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Voria Extended Class and Template Library
WWW=		https://www.synfig.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		autoreconf gnome pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	synfig
GH_PROJECT=	synfig
USE_GNOME=	glibmm

GNU_CONFIGURE=	yes

WRKSRC_SUBDIR=	ETL

OPTIONS_DEFINE=	DOCS

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
NO_ARCH=	yes
PORTSCOUT=	limitw:1,even

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
