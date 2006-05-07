# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	1.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A photorealistic rendering system

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_GCC=	3.4+
USE_GNOME=	gnometarget
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-static
INSTALLS_SHLIB=	yes

MAN1=		aqsis.1

CFLAGS+=	-fPIC
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "ia64"
BROKEN=		"Does not compile on ${MACHINE_ARCH} (needs -fPIC)"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|PLUGIN_FLAGS=|#PLUGIN_FLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
