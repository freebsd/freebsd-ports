# New ports collection makefile for:	ogle
# Date created:				Tue Oct 16 18:35:39 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogle
PORTVERSION=	0.7.5
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/
PKGNAMESUFFIX=	-gui
DISTNAME=	${PORTNAME}_gui-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake
LIB_DEPENDS=	dvdcontrol.4:${PORTSDIR}/graphics/ogle \
		intl.1:${PORTSDIR}/devel/gettext \
		jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	ogle:${PORTSDIR}/graphics/ogle

USE_X_PREFIX=	yes
USE_GNOMELIBS=	yes
USE_GTK=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-dvd-includes=${LOCALBASE}/include \
		--with-dvdcontrol=${LOCALBASE} \
		--without-included-gettext

post-patch:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

pre-configure:
.for file in intl/Makefile.in po/Makefile.in.in
	@${ECHO} 'all:' > ${WRKSRC}/${file}
	@${ECHO} 'install:' >> ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
