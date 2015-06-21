# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	gno3dtet
PORTVERSION=	1.96.1
PORTREVISION=	12
CATEGORIES=	games gnome
MASTER_SITES=	http://eseb.net/ftp/gno3dtet/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME version of the classic 3D-ified T*tris

LICENSE=	GPLv2

USES=		autoreconf pathfix gmake pkgconfig tar:tgz
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intltool libgnomeui librsvg2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_OMF=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/LIBTOOL/d; \
		s|gnome-games|gno3dtet|' ${WRKSRC}/configure.in

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^always_built_SUBDIRS/s|po||' ${WRKSRC}/Makefile.am
.endif

.include <bsd.port.mk>
