# New ports collection makefile for:	gimp-lqr
# Date created:		27 Sep 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gimp-lqr-plugin
PORTVERSION=	0.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://web.tiscali.it/carlobaldassi/GimpLqrPlugin/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Liquid rescale GIMP plug-in

LIB_DEPENDS=	gimp-2.0:${PORTSDIR}/graphics/gimp-app

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's|@USE_NLS@|no|g' ${WRKSRC}/po/Makefile.in.in
.else
	@${REINPLACE_CMD} -e 's|@USE_NLS@|yes|g' ${WRKSRC}/po/Makefile.in.in
.endif
	@${REINPLACE_CMD} -e 's|^bindir = .*|bindir = ${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
