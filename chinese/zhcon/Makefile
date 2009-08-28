# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.2.6
CATEGORIES=	chinese
MASTER_SITES=	LOCAL/chinsan/chinese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast Console Chinese System which supports framebuffer device

PORTSCOUT=	limit:^0\.2.[0-9]*

GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386
USE_ICONV=	yes
# Don't bother to add ".if !defined(WITHOUT_NLS)", zhcon requires libintl
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
MAN1=		zhcon.1

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,' ${WRKSRC}/doc/zhcon.1.in
	@${REINPLACE_CMD} -Ee 's,/dev/vga,/dev/ttyv0,g' ${WRKSRC}/src/display/fbdev.cpp
	@${REINPLACE_CMD} -Ee 's,endian,sys/endian,g' ${WRKSRC}/src/display/fblinear4.cpp \
		${WRKSRC}/src/display/fblinear8.cpp ${WRKSRC}/src/display/fblinear16.cpp \
		${WRKSRC}/src/display/fblinear24.cpp
	@${REINPLACE_CMD} -e '5 s,#,,; s,/usr/lib,${PREFIX}/lib,' ${WRKSRC}/src/zhcon.conf
	@${REINPLACE_CMD} -e 's,"/etc,"${PREFIX}/etc,'  ${WRKSRC}/src/zhcon.cpp
	@${REINPLACE_CMD} -Ee 's,(\s*=\s*)("?)/usr/local([^"]*)("?),\1\2${PREFIX}\3\4,g' \
		-e '/_nl_expand_alias/s,\(0\),\(\),g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(WITH_BIG5)
	@${REINPLACE_CMD} -e '11 s,gb2312,big5,' ${WRKSRC}/src/zhcon.conf
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
