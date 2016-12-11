# Created by: Alexander Kojevnikov <alexander@kojevnikov.com>
# $FreeBSD$

PORTNAME=	spek
PORTVERSION=	0.8.2
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	alexander@kojevnikov.com
COMMENT=	Acoustic spectrum analyser

LICENSE=	GPLv3

BROKEN=		Unfetchable (google code has gone away)

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		tar:xz gmake pkgconfig desktop-file-utils compiler:c++11-lib desktop-file-utils
USE_GNOME=	intltool
USE_WX=	3.0
WX_UNICODE=	yes
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
