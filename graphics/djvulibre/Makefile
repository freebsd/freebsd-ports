# New ports collection makefile for:	libdjvu++
# Date Created:		20 July 1999
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	djvulibre
PORTVERSION=	3.5.9
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	djvu

MAINTAINER=	coop9211@uidaho.edu

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		iconv.3:${PORTSDIR}/converters/libiconv
.ifndef WITHOUT_X11
USE_X_PREFIX= yes
USE_QT_VER=   3
.else
PKGNAMESUFFIX=	-nox11
.endif

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	JPEG_CFLAGS=-I"${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg"
CONFIGURE_ARGS=	--enable-threads=posix --enable-shared --prefix="${PREFIX}"

.ifndef WITHOUT_X11
CONFIGURE_ENV+=	CXX=${CXX} \
		PTHREAD_CFLAGS=-pthread \
		PTHREAD_LIBS=-pthread \
		QTLIBS="-L${X11BASE}/lib -lqt-mt"
.else
CONFIGURE_ARGS+=--disable-djview
.endif

.if !defined(WITH_OPTIMIZED_CFLAGS)
pre-everything:
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

.if defined(LOCALBASE) && ${LOCALBASE} != "/usr/local"
pre-configure:
	${PERL} -pi -e 's,/usr/local,${LOCALBASE},g' `find ${WRKSRC} \
		-type f -print0 | xargs -0 ${GREP} -Fl --mmap /usr/local`
.endif

.if !defined(WITH_OPTIMIZED_CFLAGS)
post-configure:
	${PERL} -pi -e 's,-O3,,;' -e 's,-mcpu=i386,,; ' \
		-e 's,^(OPTS =.*),\1 ${CFLAGS},' \
		${WRKSRC}/*/Makefile ${WRKSRC}/*/*/Makefile
.endif

MAN1=	bzz.1 c44.1 cjb2.1 cpaldjvu.1 csepdjvu.1 ddjvu.1 djvm.1 djvmcvt.1 djvu.1 \
	djvudump.1 djvuextract.1 djvumake.1 djvups.1 djvused.1 djvuserve.1 djvutxt.1
.ifndef WITHOUT_X11
MAN1+=	djview.1 nsdejavu.1
PLIST_SUB+=	X11=''
.else
PLIST_SUB+=	X11='@comment '
.endif

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
