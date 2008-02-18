# New ports collection makefile for:	gimp-lqr
# Date created:		27 Sep 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gimp-lqr-plugin
DISTVERSION=	0.4.0-4
CATEGORIES=	graphics
MASTER_SITES=	http://liquidrescale.wikidot.com/local--files/en:download-page/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Liquid rescale GIMP plug-in

LIB_DEPENDS=	gimp-2.0:${PORTSDIR}/graphics/gimp-app \
		lqr-1.0:${PORTSDIR}/graphics/liblqr-1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/^([0-9.]+)-([0-9]+)$/\1/}

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|^bindir = .*|bindir = ${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
