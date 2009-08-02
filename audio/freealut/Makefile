# New ports collection makefile for:	freealut
# Date created:				08 March 2006
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freealut
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://connect.creativelabs.com/openal/Downloads/ALUT/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	The OpenAL Utility Toolkit

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/@CFLAGS@/& -lopenal ${PTHREAD_LIBS}/g' \
		${WRKSRC}/examples/Makefile.in \
		${WRKSRC}/test_suite/Makefile.in

.include <bsd.port.post.mk>
