# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	hercules
PORTVERSION=	3.07
CATEGORIES=	emulators
MASTER_SITES=	http://www.hercules-390.org/

MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
COMMENT=	System/370, ESA/390, and z/Architecture Emulator

OPTIONS_DEFINE=	DEBUG NLS PTHREADS
OPTIONS_DEFAULT=	NLS PTHREADS
PTHREADS_DESC=	Build with pthreads instead of fthreads

USE_AUTOTOOLS=	libtool libltdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

.include <bsd.port.options.mk>

post-extract:
	@${RM} ${WRKSRC}/ltdl.*

post-patch:
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's@SOL_TCP@IPPROTO_TCP@g' ${WRKSRC}/hscutl.c
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's,^SUBDIRS = decNumber m4 po util html man . crypto,SUBDIRS = decNumber m4 po util man . crypto,g' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's,^datadir = @datadir@,datadir = ${PREFIX}/share/doc/,' ${WRKSRC}/html/Makefile.in
.endif
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		'/^libherc_la_LIBADD/s|=|= -lltdl |g'

MAN1=			cckddiag.1 dasdseq.1
MAN4=			cckd.4

post-install:
	@${CAT} ${PKGMESSAGE}

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-g
.endif

.if ${PORT_OPTIONS:MPTHREADS}
CONFIGURE_ARGS+=	--disable-fthreads
.endif

.if empty(PORT_OPTIONS:MNLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		GETTEXT="@comment "
.else
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
USE_GETTEXT=		yes
PLIST_SUB+=		GETTEXT=""
.endif

.if defined(CFLAGS)
CONFIGURE_ARGS+=	--enable-optimization="no"
.endif

.include <bsd.port.mk>
