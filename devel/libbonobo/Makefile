# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libbonobo/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	libbonobo
PORTVERSION=	2.32.0
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Component and compound document system for GNOME2

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

USES=		bison gettext pathfix pkgconfig
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_GNOME=	intlhack libxml2 orbit2 referencehack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread
MAKE_ENV=	gnomelocaledir=${PREFIX}/share/locale

MAN1=		bonobo-activation-server.1

post-patch:
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure \
		${WRKSRC}/activation-server/Makefile.in

.include <bsd.port.mk>

.endif
