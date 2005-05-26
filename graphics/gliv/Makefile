# ports collection makefile for:	gliv
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gliv
PORTVERSION=	1.9.3
CATEGORIES=	graphics
MASTER_SITES=	http://guichaz.free.fr/gliv/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image viewer that uses Gdk-Pixbuf and OpenGL

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN1=		gliv.1
MANLANG=	"" de fr ru

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/gliv.desktop \
		${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/gliv.png \
		${PREFIX}/share/gnome/pixmaps

.include <bsd.port.mk>
