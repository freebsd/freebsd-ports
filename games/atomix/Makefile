# New ports collection makefile for:   atomix
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atomix
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	http://triq.net/~jens/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A yet another little mind game

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnome libgnomeui libgnomecanvas libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_REINPLACE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
		 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";|'

.include <bsd.port.mk>
