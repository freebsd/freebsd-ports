# Created by: Sean McGovern <sean@sfarc.net>
# $FreeBSD$

PORTNAME=	faad2
PORTVERSION=	2.7
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF/faac/${PORTNAME}-src/${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio decoder

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
USE_LDCONFIG=	yes

post-extract:
	@${LN} -sf faad.man ${WRKSRC}/frontend/faad.1

post-patch:
	@${REINPLACE_CMD} -e '/AC_CONFIG_FILES(plugins/d' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|faad.man|faad.1|g' \
		${WRKSRC}/frontend/Makefile.am
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|AM_CPPFLAGS|g ; \
		 s|-iquote |-I|g' ${WRKSRC}/libfaad/Makefile.am
	@${REINPLACE_CMD} -e 's|= -DUSE_|= -fPIC -DPIC -DUSE_|g' \
		${WRKSRC}/common/mp4ff/Makefile.am
	@${ECHO_CMD} "SUBDIRS = libfaad common frontend" > \
		${WRKSRC}/Makefile.am

post-configure:
	@${REINPLACE_CMD} "s/444/644/g" ${WRKSRC}/common/mp4ff/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfaad.so.2

.include <bsd.port.mk>
