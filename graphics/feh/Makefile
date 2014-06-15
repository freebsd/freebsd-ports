# Created by: Jeremy Norris <ishmael127@home.com>
# $FreeBSD$

PORTNAME=	feh
PORTVERSION=	2.12
CATEGORIES=	graphics
MASTER_SITES=	http://feh.finalrewind.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Image viewer that utilizes Imlib2

LICENSE=	MIT

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USE_XORG=	x11 xt xinerama
USES=		gmake perl5 tar:bzip2 shebangfix desktop-file-utils
USE_EFL=	imlib2
USE_PERL5=	run

CPPFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

OPTIONS_DEFINE=	CAM
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
