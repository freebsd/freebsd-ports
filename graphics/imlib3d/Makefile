# ex:ts=8
# New ports collection makefile for:	imlib3d
# Date created:			Dec 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	imlib3d
PORTVERSION=	0.8.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ImLib3D-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl \
		fftw:${PORTSDIR}/math/fftw \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gtkmm:${PORTSDIR}/x11-toolkits/gtk-- \
		gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea \
		gtkglmm:${PORTSDIR}/x11-toolkits/gtkglarea--

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_FREETYPE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2/libxml" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-libimx --enable-optimize
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
