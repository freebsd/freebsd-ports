# Created by: Jeremy Norris <ishmael27@home.com>

PORTNAME=	gliv
PORTVERSION=	1.9.7
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://guichaz.free.fr/gliv/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image viewer that uses Gdk-Pixbuf and OpenGL

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

USES=		compiler:c11 desktop-file-utils gettext gl gmake gnome \
		localbase:ldflags pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix gtk20
USE_GL=		gl glu
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/gliv.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gliv.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
