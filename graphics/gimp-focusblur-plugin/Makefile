# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	focusblur
PORTVERSION=	3.2.6
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gimp realistic focus blur plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libgimp-2.0.so:graphics/gimp-app

USES=		gmake pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lm -L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's|^bindir = .*|bindir = ${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h|glib.h|g' \
		${WRKSRC}/src/*.[ch]

.include <bsd.port.mk>
