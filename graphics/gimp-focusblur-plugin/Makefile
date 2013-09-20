# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	focusblur
PORTVERSION=	3.2.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gimp realistic focus blur plugin

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		gimp-2.0:${PORTSDIR}/graphics/gimp-app

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^bindir = .*|bindir = ${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h|glib.h|g' \
		${WRKSRC}/src/*.[ch]

.include <bsd.port.mk>
