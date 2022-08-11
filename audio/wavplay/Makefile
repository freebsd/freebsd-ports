PORTNAME=	wavplay
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Release%20Downloads/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Wav player and recorder

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	does not play sound correctly

USES=		autoreconf libtool:build
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

X11_CONFIGURE_OFF=	--enable-nox
X11_USES=		localbase:ldflags xorg
X11_USE=		XORG=x11,xmu,xt
X11_LIB_DEPENDS=	libXm.so:x11-toolkits/lesstif

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g' ${WRKSRC}/src/*.c

.include <bsd.port.mk>
