# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A photorealistic rendering system

LIB_DEPENDS=	log4cpp.4:${PORTSDIR}/devel/log4cpp \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_MESA=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-static --datadir="${DATADIR}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -fPIC
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CFLAGS+=	-O0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|PLUGIN_FLAGS=|#PLUGIN_FLAGS=|g ; \
		 s|^CPPFLAGS="-D|CPPFLAGS="\$$CPPFLAGS -D|g ; \
		 s|^CFLAGS=|#CFLAGS=|g ; \
		 s|^CXXFLAGS=|#CXXFLAGS=|g' ${WRKSRC}/configure
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.post.mk>
