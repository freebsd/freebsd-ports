# Created by: Alexander Kojevnikov <alexander@kojevnikov.com>
# $FreeBSD$

PORTNAME=	spek
PORTVERSION=	0.8.2
PORTREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	https://github.com/alexkay/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	alexander@kojevnikov.com
COMMENT=	Acoustic spectrum analyser

LICENSE=	GPLv3+

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lib desktop-file-utils gmake gnome pkgconfig \
		tar:xz
USE_GNOME=	intltool
USE_WX=		3.0
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e "s,^itlocaledir =.*$$,itlocaledir = ${PREFIX}/share/locale,g" \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
