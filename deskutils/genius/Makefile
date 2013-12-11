# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	genius
PORTVERSION=	1.0.12
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME \
		http://ftp.5z.com/pub/genius/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment

LICENSE=	GPLv3

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	libmpfr.so:${PORTSDIR}/math/mpfr
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USE_CSTD=	gnu89
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnomevfs2 gtksourceview2 intlhack vte
USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-extra-gcc-optimization
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
