# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	yamt
PORTVERSION=	0.5
PORTREVISION=	11
CATEGORIES=	audio gnome
MASTER_SITES=	SF \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/


MAINTAINER=	demon@FreeBSD.org
COMMENT=	Yet Another Mp3 Tool which helps you to organize your mp3s

USES=		gmake pathfix
USE_GNOME=	gnomelibs gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

.include <bsd.port.mk>
