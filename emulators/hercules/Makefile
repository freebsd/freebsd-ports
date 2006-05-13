# New ports collection makefile for:	dice
# Date created:		Thu Jan 31 12:07:01 CET 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	hercules
PORTVERSION=	3.04
CATEGORIES=	emulators
MASTER_SITES=	http://www.conmicro.cx/hercules/

MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
COMMENT=	The Hercules System/370, ESA/390, and z/Architecture Emulator

OPTIONS=	PTHREADS "Build with pthreads instead of fthreads." on \
		NLS "Build with native language support." on \
		DEBUG "Enable for debugging hercules itself." off

GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes

post-patch:
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's,intl m4 po util html man,intl m4 po util man,g' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's,^datadir = @datadir@,datadir = ${PREFIX}/share/doc/,' ${WRKSRC}/html/Makefile.in
.endif

MAN1=			cckddiag.1 dasdseq.1
MAN4=			cckd.4

.if !defined(NOPORTDOCS)
PORTDOCS=		*
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not compile on FreeBSD 4.x
.endif

.if defined(WITH_DEBUG)
CFLAGS+=		-g
.endif
.if defined(WITH_PTHREADS)
CONFIGURE_ARGS+=	--disable-fthreads
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		GETTEXT="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		GETTEXT=""
.endif

.if defined(CFLAGS)
CONFIGURE_ARGS+=	--enable-optimization="no"
.endif

.include <bsd.port.post.mk>
