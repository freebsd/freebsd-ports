# Ports collection makefile for:  wormux
# Date created:			  Thu Dec 16 18:46:55 EET 2004
# Whom:				  Anton Yudin <toha@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wormux
DISTVERSION=	0.9.2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/wormux/ \
		http://download.gna.org/wormux/archive/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Wormux game

LIB_DEPENDS=	xml++-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		curl:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image mixer ttf gfx net
MAKE_JOBS_SAFE=	yes
USE_DOS2UNIX=	fixed_class.h

MANCOMPRESSED=	no
MAN6=	wormux.6

post-patch:
	${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/Makefile.in \
	${WRKSRC}/src/Makefile.in
	${FIND} -d ${WRKSRC}/data/ -name "*.*~" -delete

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
