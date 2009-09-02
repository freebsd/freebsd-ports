# New ports collection makefile for:	xmms-ahx
# Date created:				2 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	xmms-ahx
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS plugin for playing AHX tunes

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	lib/xmms/Input/libahx.la \
		lib/xmms/Input/libahx.so

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|\(objformat=\).*|\1elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
