# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	stk
PORTVERSION=	4.6.0
CATEGORIES=	audio
MASTER_SITES=	http://ccrma.stanford.edu/software/stk/release/

MAINTAINER=	yuri@rawbw.com
COMMENT=	Synthesis ToolKit in C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjack.so:audio/jack

USES=		autoreconf dos2unix gmake pkgconfig localbase
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jack --with-oss
DOS2UNIX_GLOB=	*.cpp *.h
MAKE_ARGS=	RAWWAVES=${DATADIR}/rawwaves/

post-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} rawwaves ${STAGEDIR}${DATADIR}
	@${RM} ${STAGEDIR}${DATADIR}/rawwaves/._* ${STAGEDIR}${DATADIR}/rawwaves/*.c
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libstk-${PORTVERSION}.so

.include <bsd.port.mk>
