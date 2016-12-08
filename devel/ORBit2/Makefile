# Created by: Chia-liang Kao <clkao@CirX.ORG>
# $FreeBSD$
#   $MCom: ports/trunk/devel/ORBit2/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	ORBit2
PORTVERSION=	2.14.19
PORTREVISION?=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	High-performance CORBA ORB with support for the C language

USES=		tar:bzip2

.if !defined(REFERENCE_PORT)

GNU_CONFIGURE=	yes
USES+=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	libidl referencehack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/orb/orb-core/orbit-typelib.c
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure ${WRKSRC}/linc2/src/Makefile.in
	@${REINPLACE_CMD} '/DESTDIR.*RANLIB/d' \
		${WRKSRC}/src/services/name/Makefile.in

post-install:
	@${ECHO_CMD} "ORBIIOPIPv4=0" > ${STAGEDIR}${PREFIX}/etc/orbit2rc.sample
	@${ECHO_CMD} "ORBIIOPIPv6=0" >> ${STAGEDIR}${PREFIX}/etc/orbit2rc.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/orbit-2.0/idl-backends

.include <bsd.port.mk>

.endif
