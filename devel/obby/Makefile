# Ports collection makefile for:	obby
# Date created:				2005-10-14
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	obby
PORTVERSION=	0.4.3
CATEGORIES=	devel
MASTER_SITES=	http://releases.0x539.de/obby/ \
		http://www.atarininja.org/~wxs/distfiles/

MAINTAINER=	wxs@atarininja.org
COMMENT=	A library for synced document buffers

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		net6:${PORTSDIR}/net/net6

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--without-howl
USE_LDCONFIG=		yes

.if !defined(WITHOUT_NLS)
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$$(prefix)/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	some dependencies does not run on FreeBSD < 5.x
.endif

.include <bsd.port.post.mk>
