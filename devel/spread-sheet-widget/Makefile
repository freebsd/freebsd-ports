PORTNAME=	spread-sheet-widget
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNU_ALPHA/ssw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for GTK which provides widget for tabular data
WWW=		https://www.gnu.org/software/ssw/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gmake gnome libtool pkgconfig
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

INFO=		spread-sheet-widget
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
