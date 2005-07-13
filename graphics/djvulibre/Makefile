# New ports collection makefile for:	libdjvu++
# Date Created:		20 July 1999
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	djvulibre
PORTVERSION=	3.5.14
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	djvu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DjVu viewers, encoders, browser plugin, and utilities

.if !defined(WITHOUT_X11)
USE_X_PREFIX=	yes
USE_QT_VER=	3
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.else
PKGNAMESUFFIX=	-nox11
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
.endif

USE_ICONV=	yes
USE_PERL5_BUILD=yes
USE_AUTOCONF_VER=259
USE_INC_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
DATADIR=	${PREFIX}/share/djvu
CONFIGURE_ENV=	JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		TIFF_CFLAGS="-I${LOCALBASE}/include" \
		TIFF_LIBS="-L${LOCALBASE}/lib -ltiff"
CONFIGURE_ARGS=	--enable-threads=pthread --enable-shared --prefix="${PREFIX}"

.if !defined(WITHOUT_X11)
CONFIGURE_ENV+=	CXX=${CXX} \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		QTLIBS="-L${X11BASE}/lib -lqt-mt"
.else
CONFIGURE_ARGS+=--disable-djview
.endif

.if !defined(WITH_OPTIMIZED_CFLAGS)
pre-everything::
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

.if defined(LOCALBASE) && ${LOCALBASE} != "/usr/local"
pre-configure:
	${PERL5} -pi -e 's,/usr/local,${LOCALBASE},g' `${FIND} ${WRKSRC} \
		-type f -print0 | ${XARGS} -0 ${GREP} -Fl --mmap /usr/local`
.endif

patch-autotools:
	@cd ${PATCH_WRKSRC}; ${LIBTOOLIZE} -f >/dev/null

post-patch:
	@${RM} ${WRKSRC}/tools/any2djvu.*

.if !defined(WITH_OPTIMIZED_CFLAGS)
post-configure:
	${PERL5} -pi -e 's,-O3,,;' -e 's,-mcpu=i386,,; ' \
		-e 's,^(OPTS =.*),\1 ${CFLAGS},' \
		${WRKSRC}/*/Makefile ${WRKSRC}/*/*/Makefile
.endif

PORTDOCS=	djvu2spec.djvu djvu3changes.txt lizard2002.djvu
MANLANG="" ja
MAN1=	bzz.1 c44.1 cjb2.1 cpaldjvu.1 csepdjvu.1 ddjvu.1 djvm.1 djvmcvt.1 djvu.1 \
	djvudump.1 djvuextract.1 djvumake.1 djvups.1 djvused.1 djvuserve.1 djvutxt.1

MAN1EXTRA=	djvutoxml.1 djvuxml.1 djvuxmlparser.1 djvudigital.1
MAN1+=		${MAN1EXTRA}

.if !defined(WITHOUT_X11)
MAN1+=	djview.1 nsdejavu.1
PLIST_SUB+=	X11=''
.else
PLIST_SUB+=	X11='@comment '
.endif

post-install:
.for man1 in ${MAN1EXTRA}
.for manlang in ${MANLANG}
	${TOUCH} ${MAN1PREFIX}/man/${manlang}/man1/${man1}
.endfor
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
