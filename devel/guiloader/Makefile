# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	guiloader
PORTVERSION=	2.19.0
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance and compact GuiXml loader library

BROKEN=		Unfetchable (google code has gone away)

PROJECTHOST=	nothing-personal
USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-hidden-visibility
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libguiloader.so.1

.include <bsd.port.mk>
