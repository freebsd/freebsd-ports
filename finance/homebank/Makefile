# $FreeBSD$

PORTNAME=	homebank
PORTVERSION=	5.0.3
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Free, easy, personal accounting for everyone

LICENSE=	GPLv2

LIB_DEPENDS=	libosp.so:${PORTSDIR}/textproc/opensp

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake pkgconfig shared-mime-info
USE_GNOME=	gtk30
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS OFX
OFX_DESC=	OFX file format support
OPTIONS_DEFAULT=OFX

OFX_CONFIGURE_WITH=	ofx
OFX_LIB_DEPENDS=	libofx.so:${PORTSDIR}/finance/libofx

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
