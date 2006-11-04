# New ports collection makefile for:   pcmanx
# Date created:                2005/07/16
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pcmanx
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	chinese net gnome
MASTER_SITES=	http://pcmanx.csie.net/release/
DISTNAME=	${PORTNAME}-gtk2-${PORTVERSION}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	BBS client using GTK+ 2.x

USE_GNOME=	gtk20 intlhack
USE_GCC=	3.3+
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_LDCONFIG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/wget/fetch/' ${WRKSRC}/po/zh_CN.po
	@${REINPLACE_CMD} -e 's/wget/fetch/' ${WRKSRC}/po/zh_TW.po
	@${REINPLACE_CMD} -e 's/wget -O/fetch -o/' ${WRKSRC}/src/mainframe.cpp
	@${REINPLACE_CMD} -e 's/wget/fetch/' ${WRKSRC}/src/generalprefpage.cpp
	@${REINPLACE_CMD} -e 's/wget/fetch/' ${WRKSRC}/src/view/telnetview.cpp

.include <bsd.port.mk>
