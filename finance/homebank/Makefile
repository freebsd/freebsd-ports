# $FreeBSD$

PORTNAME=	homebank
PORTVERSION=	4.5.2
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Free, easy, personal accounting for everyone

LICENSE=	GPLv2

LIB_DEPENDS=	osp:${PORTSDIR}/textproc/opensp

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gmake shared-mime-info
USE_GNOME=	gnomehier gtk20
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS OFX
OFX_DESC=	OFX file format support
OPTIONS_DEFAULT=OFX

OFX_LIB_DEPENDS=	ofx:${PORTSDIR}/finance/libofx
OFX_CONFIGURE_OFF=	--without-ofx

.include <bsd.port.options.mk>

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
