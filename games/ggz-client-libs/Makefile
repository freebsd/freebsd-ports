# ex:ts=8
# Ports collection makefile for:	ggz-client-libs
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ggz-client-libs
PORTVERSION=	0.0.11
CATEGORIES=	games
MASTER_SITES=	http://ftp.ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Core Client Libraries

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		ggz.3:${PORTSDIR}/games/libggz \
		expat.5:${PORTSDIR}/textproc/expat2

USE_GNOME=	gnometarget
USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug
INSTALLS_SHLIB=	yes

MAN3=	ggzcore_h.3 ggzmod_h.3
MAN5=	ggz.modules.5
MAN6=	ggz-config.6 ggz-wrapper.6

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|LIBGGZ_INCLUDES=.*$$|LIBGGZ_INCLUDES=|g ; \
		 s|LIBGGZ_LDFLAGS=.*$$|LIBGGZ_LDFLAGS=|g ; \
		 s|libggz.la|libggz.so|g' ${WRKSRC}/configure

.include <bsd.port.mk>
