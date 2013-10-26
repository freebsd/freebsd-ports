# Created by: Alexander Kojevnikov <alexander@kojevnikov.com>
# $FreeBSD$

PORTNAME=	spek
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	alexander@kojevnikov.com
COMMENT=	Acoustic spectrum analyser

LICENSE=	GPLv3

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

USE_XZ=		yes
USES=		gmake pkgconfig desktop-file-utils
USE_GNOME=	desktopfileutils intltool
USE_WX=	2.8+
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000054
USE_GCC=	4.7+
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,^itlocaledir =.*$$,itlocaledir = ${PREFIX}/share/locale,g" \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.post.mk>
