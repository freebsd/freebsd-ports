# Created by: Serge Gagnon <gagnon__s@videotron.ca>
# $FreeBSD$

PORTNAME=	xvmixer
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ftp.auxio.org/pub/mirrors/step.polymtl.ca/pub/Xview/apps/xvmixer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Look-based audio mixer

LIB_DEPENDS=	libxview.so:x11-toolkits/xview

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include -DUSE_XBM_ICON" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBRARIES="-lxview -lolgx -lX11"
PLIST_FILES=	bin/xvmixer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvmixer ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
