# New ports collection makefile for:	grhino
# Date created:				21 Sep 2002
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	grhino
PORTVERSION=	0.15.0
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rhino

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	GRhino Othello/Reversi Program

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix libgnomeui
USE_GCC=	3.4+
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_OMF=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
