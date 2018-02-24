# $FreeBSD$

PORTNAME=	homebank
PORTVERSION=	5.1.7
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, easy, personal accounting for everyone

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libosp.so:textproc/opensp

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake localbase pkgconfig \
		shared-mime-info
USE_GNOME=	cairo gtk30 intltool
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS OFX
OFX_DESC=	OFX file format support
OPTIONS_DEFAULT=OFX

OFX_CONFIGURE_WITH=	ofx
OFX_LIB_DEPENDS=	libofx.so:finance/libofx

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
