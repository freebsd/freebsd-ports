PORTNAME=	stk
DISTVERSION=	5.0.0
CATEGORIES=	audio
MASTER_SITES=	http://ccrma.stanford.edu/software/stk/release/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synthesis ToolKit in C++
WWW=		https://ccrma.stanford.edu/software/stk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang dos2unix gmake localbase pkgconfig
USE_LDCONFIG=	yes

DOS2UNIX_GLOB=	*.cpp *.h

GNU_CONFIGURE=	yes

MAKE_ARGS=	RAWWAVES=${DATADIR}/rawwaves/

LDFLAGS+=	-pthread

OPTIONS_RADIO=		BACKEND
OPTIONS_RADIO_BACKEND=	JACK OSS
OPTIONS_DEFAULT=	OSS

BACKEND_DESC=		Audio Backend

JACK_CONFIGURE_WITH=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack

OSS_CONFIGURE_WITH=	oss

post-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} rawwaves ${STAGEDIR}${DATADIR}
	@${RM} ${STAGEDIR}${DATADIR}/rawwaves/._* ${STAGEDIR}${DATADIR}/rawwaves/*.c
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libstk-${PORTVERSION}.so

.include <bsd.port.mk>
