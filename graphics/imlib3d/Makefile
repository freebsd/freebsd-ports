# ex:ts=8
# New ports collection makefile for:	imlib3d
# Date created:			Dec 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	imlib3d
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ImLib3D-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		gsl.4:${PORTSDIR}/math/gsl \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gtkglmm.1:${PORTSDIR}/x11-toolkits/gtkglarea--

USE_X_PREFIX=	yes
USE_MESA=	yes
#USE_FREETYPE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-optimize
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
#BROKEN=		"does not build with GCC 2.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|OPTIMIZE_FLAGS=.*$$|OPTIMIZE_FLAGS=|g ; \
		 s|<xmlversion.h>|<libxml/xmlversion.h>|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
