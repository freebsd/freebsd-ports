# Created by: Chia-liang Kao <clkao@CirX.ORG>
# $FreeBSD$
#   $MCom: ports/trunk/devel/ORBit2/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	ORBit2
PORTVERSION=	2.14.19
PORTREVISION?=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	High-performance CORBA ORB with support for the C language

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USES=		gettext pathfix pkgconfig gmake
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	libidl ltverhack referencehack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/orb/orb-core/orbit-typelib.c
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure ${WRKSRC}/linc2/src/Makefile.in

post-install:
	@${ECHO_CMD} "ORBIIOPIPv4=0" > ${STAGEDIR}${PREFIX}/etc/orbit2rc.default
	@${ECHO_CMD} "ORBIIOPIPv6=0" >> ${STAGEDIR}${PREFIX}/etc/orbit2rc.default
	@if [ ! -f ${STAGEDIR}${PREFIX}/etc/orbit2rc ]; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/orbit2rc.default ${STAGEDIR}${PREFIX}/etc/orbit2rc ; \
	fi
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/orbit-2.0/idl-backends

.include <bsd.port.mk>

.endif
