# New ports collection makefile for:	sdcc
# Date created:				18 Nov 2004
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdcc
PORTVERSION=	2.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small Device C Compiler

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	docdir=${DOCSDIR}
CONFIGURE_ENV+=		LDFLAGS=-L${PREFIX}/lib

.if defined(WITHOUT_UCSIM)
CONFIGURE_ARGS+=	--disable-ucsim
PLIST_SUB+=	UCSIM="@comment "
.else
PLIST_SUB+=	UCSIM=""
MAN1+=		sdcdb.1 serialview.1 ucsim.1
MLINKS+=	ucsim.1 s51.1 ucsim.1 savr.1 ucsim.1 sz80.1
.endif

.if defined(WITHOUT_DEVICE_LIB)
CONFIGURE_ARGS+=	--disable-device-lib-build
PLIST_SUB+=	DEVICE_LIB="@comment "
.else
PLIST_SUB+=	DEVICE_LIB=""
.endif

.if defined(WITHOUT_PACKIHX)
CONFIGURE_ARGS+=	--disable-packihx
PLIST_SUB+=	PACKIHX="@comment "
.else
PLIST_SUB+=	PACKIHX=""
MAN1+=		packihx.1
.endif

.if defined(WITH_LIBGC)
LIB_DEPENDS=		gc.1:${PORTSDIR}/devel/boehm-gc
CONFIGURE_ARGS+=	--enable-libgc
.endif

.if defined(NOPORTDOCS)
MAKE_ARGS+=	NOPORTDOCS=1
.endif

MAN1+=		aslink.1 asxxxx.1 makebin.1 sdcc.1 sdcpp.1
MLINKS+=	aslink.1 link-gbz80.1 aslink.1 link-hc08.1 aslink.1 link-z80.1 \
		asxxxx.1 as-gbz80.1 asxxxx.1 as-hc08.1 asxxxx.1 as-z80.1 \
		asxxxx.1 asx8051.1

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-everything::
.if !defined(WITHOUT_UCSIM)
	@${ECHO_MSG} "Define WITHOUT_UCSIM to disable building of ucsim (debug tools)"
.endif
.if !defined(WITHOUT_DEVICE_LIB)
	@${ECHO_MSG} "Define WITHOUT_DEVICE_LIB to not to build/install device libraries and headers"
.endif
.if !defined(WITHOUT_PACKIHX)
	@${ECHO_MSG} "Define WITHOUT_PACKIHX to disable building of packihx"
.endif
.if !defined(WITH_LIBGC)
	@${ECHO_MSG} "Define WITH_LIBGC to use the Bohem memory allocator (lower runtime footprint)"
.endif

post-install:
.for m in ${MAN1}
	@${INSTALL_MAN} ${FILESDIR}/${m} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
