# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	gimp-lqr-plugin
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://liquidrescale.wdfiles.com/local--files/en:download-page-sources/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Liquid rescale GIMP plug-in

LIB_DEPENDS=	libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app \
		liblqr-1.so:${PORTSDIR}/graphics/liblqr-1

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|^bindir = .*|bindir = ${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
