# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	hercules
PORTVERSION=	3.09
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.hercules-390.eu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System/370, ESA/390, and z/Architecture Emulator

OPTIONS_DEFINE=	DEBUG PTHREADS OPTIMIZATIONS DOCS
OPTIONS_DEFAULT=	PTHREADS
PTHREADS_DESC=	Build with pthreads instead of fthreads
OPTIMIZATIONS_DESC=	Enable optimizations

USE_AUTOTOOLS=	libtool libltdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I/usr/local/include
LDFLAGS+=	-L/usr/local/lib

PORTDOCS=	*

DEBUG_CFLAGS=	-g
PTHREADS_CONFIGURE_ON=	--disable-fthreads
OPTIMIZATIONS_CONFIGURE_ON=	--enable-optimization="yes"
OPTIMIZATIONS_CONFIGURE_OFF=	--enable-optimization="no"

post-extract:
	@${RM} ${WRKSRC}/ltdl.*

post-patch:
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's@SOL_TCP@IPPROTO_TCP@g' ${WRKSRC}/hscutl.c
	@${REINPLACE_CMD} -e 's,^datadir = @datadir@,datadir = ${PREFIX}/share/doc/,' ${WRKSRC}/html/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		'/^libherc_la_LIBADD/s|=|= -lltdl |g'

.include <bsd.port.mk>
