# New ports collection makefile for:	dia
# Date created:        21 December 1999
# Whom:                saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	dia
PORTVERSION=	0.90
CATEGORIES+=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/dia/0.90

MAINTAINER?=	gnome@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		freetype.9:${PORTSDIR}/print/freetype2 \
		unicode.0:${PORTSDIR}/devel/libunicode

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf bonobo
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-gnome --enable-gnome-print --enable-bonobo \
		--enable-freetype
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		dia.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	${SED} "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/dia.sh > ${WRKDIR}/dia.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dia.sh ${PREFIX}/bin/dia

.include <bsd.port.mk>
