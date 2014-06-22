# Created by: Marco Molteni <molter@gufi.org>
# $FreeBSD$

PORTNAME=	gpsdrive
PORTVERSION=	2.09
PORTREVISION=	15
CATEGORIES=	astro geography
MASTER_SITES=	http://www.gpsdrive.de/packages/ \
		LOCAL/beech

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPS navigation system

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake libtool perl5 pkgconfig
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-garmin
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lgmodule-2.0
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's/test "$$CC" = "gcc"/false/' ${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} 's|SUBDIRS = src po man|SUBDIRS = src man|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
