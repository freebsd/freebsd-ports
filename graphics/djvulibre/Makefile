# New ports collection makefile for:	libdjvu++
# Date Created:		20 July 1999
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	djvulibre
PORTVERSION=	3.5.16
PORTREVISION=	2
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	djvu

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	DjVu viewers, encoders, browser plugin, and utilities

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		TIFF_CFLAGS="-I${LOCALBASE}/include" \
		TIFF_LIBS="-L${LOCALBASE}/lib -ltiff" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CXX="${CXX}" \
		X11BASE="${X11BASE}"
CONFIGURE_ARGS=	--enable-threads=pthread --enable-shared
INSTALLS_SHLIB=	yes

MANLANG=	"" ja
MAN1=		bzz.1 c44.1 cjb2.1 cpaldjvu.1 csepdjvu.1 ddjvu.1 djvm.1 \
		djvmcvt.1 djvu.1 djvudump.1 djvuextract.1 djvumake.1 djvups.1 \
		djvused.1 djvuserve.1 djvutxt.1
MAN1EXTRA=	any2djvu.1 djvutoxml.1 djvuxml.1 djvuxmlparser.1 djvudigital.1
MAN1+=		${MAN1EXTRA}

PORTDOCS=	djvu2spec.djvu djvu3changes.txt lizard2002.djvu \
		lizard2003-navm.djvu lizard2005-antz.djvu

.if !defined(WITHOUT_X11)
USE_QT_VER=	3
CONFIGURE_ENV+=	QTLIBS="-L${X11BASE}/lib -lqt-mt"
MAN1+=		djview.1 nsdejavu.1
PLIST_SUB+=	X11=''
.else
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--disable-djview --without-x
PLIST_SUB+=	X11='@comment '
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-O\*/d ; \
		 s|$$OPTS -O3|$$OPTS|g ; \
		 s|$$OPTS -O2|$$OPTS|g ; \
		 s|$$OPTS $$opt|$$OPTS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^#! /bin/bash|#! ${LOCALBASE}/bin/bash|g ; \
		 s|any2djvu\.sh|any2djvu|g' ${WRKSRC}/tools/any2djvu
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|= @CPPFLAGS|= $${FLAGS} @CPPFLAGS|g ; \
		 s|@ $${FLAGS}|@|g ; \
		 s|} $${FLAGS}|}|g ; \
		 s|/netscape/|/djvulibre/|g ; \
		 s|eucjp|eucJP|g ; \
		 s|_PROGRAM} -m|} -m|g'

post-install:
.for man1 in ${MAN1EXTRA}
.for manlang in ${MANLANG}
	${TOUCH} ${MAN1PREFIX}/man/${manlang}/man1/${man1}
.endfor
.endfor
.if !defined(WITHOUT_X11)
	@${MKDIR} ${X11BASE}/lib/browser_plugins
	${LN} -sf ${PREFIX}/lib/djvulibre/plugins/nsdejavu.so \
		${X11BASE}/lib/browser_plugins/nsdejavu.so
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
