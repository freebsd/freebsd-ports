PORTNAME=	gmdb2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Official GUI for mdbtools

LICENSE=	GPLv2

BUILD_DEPENDS=	gawk:lang/gawk \
		itstool:textproc/itstool \
		yelp-check:textproc/yelp-tools
LIB_DEPENDS=	libmdb.so:databases/mdbtools

USES=		autoreconf gettext gmake gnome iconv libtool \
		pkgconfig readline
USE_GITHUB=	yes
GH_ACCOUNT=	mdbtools
USE_GNOME=	gdkpixbuf2 glib20 gtk30 libxml2
GLIB_SCHEMAS=	mdbtools.gmdb2.gschema.xml
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS=		AUTHORS CHANGELOG.md README.md TODO

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
