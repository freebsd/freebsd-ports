# New ports collection makefile for:	grhino
# Date created:				21 Sep 2002
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	grhino
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rhino

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	GRhino Othello/Reversi Program

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk20 gnomeprefix gnomelibs pkgconfig
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
