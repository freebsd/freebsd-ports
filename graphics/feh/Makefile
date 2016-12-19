# Created by: Jeremy Norris <ishmael127@home.com>
# $FreeBSD$

PORTNAME=	feh
PORTVERSION=	2.18
CATEGORIES=	graphics
MASTER_SITES=	http://feh.finalrewind.org/ \
		LOCAL/uqs

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Image viewer that utilizes Imlib2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libImlib2.so:graphics/imlib2 \
		libpng16.so:graphics/png

USE_XORG=	x11 xt xinerama
USES=		cpe desktop-file-utils gmake perl5 shebangfix tar:bzip2
CPE_VENDOR=	daniel_friesel
USE_PERL5=	run

CPPFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

OPTIONS_DEFINE=	CAM DOCS
CAM_DESC=	Install feh-cam and related tools
OPTIONS_DEFAULT=CAM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAM}
MAKE_ENV+=	cam=1
SHEBANG_FILES=	${WRKSRC}/cam/feh-cam
PLIST_SUB=	CAM=""
.else
MAKE_ENV+=	cam=0
PLIST_SUB=	CAM="@comment "
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/feh

.include <bsd.port.mk>
