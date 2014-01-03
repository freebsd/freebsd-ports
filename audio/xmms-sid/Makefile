# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-sid
PORTVERSION=	0.9.2
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS input plugin to play SID files

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	xmms>0:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms>0:${PORTSDIR}/multimedia/xmms

OPTIONS_DEFINE=	NLS SIDPLAY2
SIDPLAY2_DESC=	LibSIDPlay2 support
OPTIONS_SUB=	yes

USE_BZIP2=	yes
USES=		gettext
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSIDPLAY2}
LIB_DEPENDS+=	libsidplay2.so:${PORTSDIR}/audio/libsidplay2
USES+=		pkgconfig
CONFIGURE_ARGS+=--with-sidplay2 --without-sidplay1
.else
LIB_DEPENDS+=	libsidplay.so:${PORTSDIR}/audio/libsidplay
CONFIGURE_ARGS+=--with-sidplay1 --without-sidplay2
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|--libs libsidplay2|--libs-only-L libsidplay2|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
