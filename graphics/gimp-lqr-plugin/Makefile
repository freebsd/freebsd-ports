PORTNAME=	gimp-lqr-plugin
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://liquidrescale.wdfiles.com/local--files/en:download-page-sources/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Liquid rescale GIMP plug-in
WWW=		https://liquidrescale.wikidot.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app \
		liblqr-1.so:graphics/liblqr-1

USES=		compiler:c++11-lang gettext gmake gnome localbase pkgconfig \
		tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool

CFLAGS+=	-fcommon

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^bindir = .*|bindir = ${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
