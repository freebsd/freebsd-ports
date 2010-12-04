# ex:ts=8
# New ports collection makefile for:	sng
# Date created:			Mar 20, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sng
PORTVERSION=	1.0.5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	corky1951@comcast.net
COMMENT=	Compiler/decompiler for Scriptable Network Graphics

BUILD_DEPENDS=	${LOCALBASE}/lib/X11/rgb.txt:${PORTSDIR}/x11/rgb
RUN_DEPENDS=	${LOCALBASE}/lib/X11/rgb.txt:${PORTSDIR}/x11/rgb
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-png-inc=${LOCALBASE}/include \
		--with-rgbtxt=${LOCALBASE}/lib/X11/rgb.txt

MAN1=		sng.1
PLIST_FILES=	bin/sng bin/sng_regress

pre-patch:
	@${REINPLACE_CMD} -e 's|-static||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '33,34s|^static ||' ${WRKSRC}/sngd.c

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sng_regress ${PREFIX}/bin

.include <bsd.port.mk>
