# ex:ts=8
# Ports collection makefile for:	nova
# Date created:			Apr 16, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nova
PORTVERSION=	0.4
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Integrated Observational Environment for amatuer astronomers

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		gtkmm-2.0.6:${PORTSDIR}/x11-toolkits/gtk--2 \
		gnomemm-2.0.1:${PORTSDIR}/x11/libgnomemm \
		glademm-2.0.1:${PORTSDIR}/devel/libglademm \
		gconfmm-2.0.1:${PORTSDIR}/devel/gconfmm \
		gnomecanvasmm-2.0.1:${PORTSDIR}/graphics/libgnomecanvasmm \
		gnomeuimm-2.0.1:${PORTSDIR}/x11-toolkits/libgnomeuimm \
		xml\\+\\+-1.0.1:${PORTSDIR}/textproc/libxml++ \
		nova-0.9.0:${PORTSDIR}/astro/libnova
RUN_DEPENDS=	${LOCALBASE}/share/nova/catalogs/sky2000.ncd:${PORTSDIR}/astro/sky2000

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile with gcc 2.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/nova/,/share/nova/,' ${WRKSRC}/configure

.include <bsd.port.post.mk>
