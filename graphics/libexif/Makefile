# New ports collection makefile for:    libexif
# Date created:        Tue Feb 26 19:02:44 MST 2002
# Whom:                Peter Schmiedeskamp
#
# $FreeBSD$
#

PORTNAME=	libexif
PORTVERSION=	0.5.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pschmied@qwest.net

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-g -Wall||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

.include <bsd.port.mk>
