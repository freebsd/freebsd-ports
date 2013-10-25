# Created by: Marco Molteni <molter@gufi.org>
# $FreeBSD$

PORTNAME=	gpsdrive
PORTVERSION=	2.09
PORTREVISION=	14
CATEGORIES=	astro geography
MASTER_SITES=	http://www.gpsdrive.de/packages/ \
		LOCAL/beech

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPS navigation system

LICENSE=	GPLv2

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USES=		gmake perl5 pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-garmin
MAKE_JOBS_UNSAFE=	yes

MANLANG=	"" de es

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} 's|SUBDIRS = src po man|SUBDIRS = src man|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
