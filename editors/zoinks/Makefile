# Created by: Mike Lockwood <mike@mikelockwood.com>
# $FreeBSD$

PORTNAME=	zoinks
PORTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://zoinks.mikelockwood.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 programmer's editor and development environment

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		's|^MY_CXXFLAGS|#&|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name *.xpm | ${XARGS} ${REINPLACE_CMD} -e \
		's|^"|(char *)"|g'

.include <bsd.port.mk>
