# Created by: Mike Lockwood <mike@mikelockwood.com>
# $FreeBSD$

PORTNAME=	zoinks
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://zoinks.mikelockwood.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 programmer's editor and development environment

LICENSE=	GPLv2 # (or later)

USE_XORG=	xpm
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		IMLIB NLS
OPTIONS_SUB=		yes

IMLIB_USE=		GNOME=imlib
IMLIB_CONFIGURE_ENABLE=	imlib
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		's|^MY_CXXFLAGS|#&|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name *.xpm | ${XARGS} ${REINPLACE_CMD} -e \
		's|^"|(char *)"|g'

.include <bsd.port.mk>
