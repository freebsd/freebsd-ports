# New ports collection makefile for:   pcmanx
# Date created:                2005/07/16
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pcmanx
PORTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	chinese net gnome
MASTER_SITES=	http://pcmanx.csie.net/release/ \
		LOCAL/chinsan
DISTNAME=	${PORTNAME}-gtk2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BBS client using GTK+ 2.x

USE_BZIP2=	yes
USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	WGET	"enable wget support for download articles" on

.if !defined(WITHOUT_WGET)
RUN_DEPENDS+=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget
CONFIGURE_ARGS+=--enable-wget
.endif

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
	@${REINPLACE_CMD} -e 's/wget/fetch/' ${WRKSRC}/po/zh_CN.po \
		${WRKSRC}/po/zh_TW.po ${WRKSRC}/src/generalprefpage.cpp \
		${WRKSRC}/src/view/telnetview.cpp
	@${REINPLACE_CMD} -e 's/wget -O/fetch -o/' ${WRKSRC}/src/mainframe.cpp
	@${REINPLACE_CMD} -e 's/Antiidlestr/AntiIdleStr/' \
		${WRKSRC}/src/appconfig.cpp
	@${REINPLACE_CMD} -e '136 s/, \(.*\)/,1\);/' \
	  	${WRKSRC}/src/view/telnetview.cpp

.include <bsd.port.mk>
