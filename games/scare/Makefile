# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scare
PORTVERSION=	1.3.10
CATEGORIES=	games
MASTER_SITES=	http://ifarchive.flavorplex.com/%SUBDIR%/ \
		http://ifarchive.heanet.ie/%SUBDIR%/ \
		http://ifarchive.jmac.org/%SUBDIR%/ \
		http://ifarchive.plover.net/%SUBDIR%/ \
		http://ifarchive.wurb.com/%SUBDIR%/ \
		http://www.ifarchive.org/%SUBDIR%/ \
		ftp://ftp.ifarchive.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	if-archive/programming/adrift

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ADRIFT-compatible interactive games interpreter

LICENSE=	GPLv2

OPTIONS_DEFINE=	XGLK
XGLK_DESC=	Use the xglk graphics library

USES=		zip

PLIST_FILES=	bin/scare

XGLK_BUILD_DEPENDS=	${LOCALBASE}/lib/libxglk.a:${PORTSDIR}/games/xglk
XGLK_RUN_DEPENDS=	${LOCALBASE}/lib/libxglk.a:${PORTSDIR}/games/xglk
XGLK_ALL_TARGET=	scare glkscare
XGLK_PLIST_FILES=	bin/glkscare

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s|= |?= | ; \
		 /^CFLAGS/s|= -O2|+= | ; \
		 /^CFLAGS/s|-fPIC|| ; \
		 /^LDLIBS/s|=.*|= -lz| ; \
		 /-D__unix/s|^#|| ; \
		 s|^sinclude.*|.include "$$(GLKPATH)/Make.$$(GLK)"| ; \
		 s| $$(ZOBJECTS)||' ${WRKSRC}/source/Makefile

do-configure:
	@${MKDIR} ${WRKDIR}/xglk
.if ${PORT_OPTIONS:MXGLK}
	@${LN} -sf ${LOCALBASE}/include/xglk/*.h ${WRKDIR}/xglk
	@${LN} -sf ${LOCALBASE}/share/xglk/Make.xglk ${WRKDIR}/xglk
.else
	@${TOUCH} ${WRKDIR}/xglk/Make.xglk
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/scare ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MXGLK}
	${INSTALL_PROGRAM} ${WRKSRC}/source/glkscare ${STAGEDIR}${PREFIX}/bin
.endif

test:	build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.mk>
