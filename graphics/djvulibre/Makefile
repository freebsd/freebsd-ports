# New ports collection makefile for:	libdjvu++
# Date Created:		20 July 1999
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	djvulibre
PORTVERSION=	3.5.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	djvu

MAINTAINER=	john_m_cooper@yahoo.com

BROKEN=		"Does not compile"

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		iconv.3:${PORTSDIR}/converters/libiconv
.ifndef WITHOUT_X11
USE_QT_VER=	2
#LIB_DEPENDS+=	qt2:${PORTSDIR}/x11-toolkits/qt23
.else
PKGNAMESUFFIX=	-nox11
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	JPEG_CFLAGS=-I"${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg"
CONFIGURE_ARGS=	--enable-threads=posix --enable-shared # --enable-rpo

.ifndef WITHOUT_X11
CONFIGURE_ENV+=	CXX=${CXX} PTHREAD_CFLAGS=-pthread PTHREAD_LIBS=-pthread \
		MOC=${LOCALBASE}/bin/moc2 UIC=${LOCALBASE}/bin/uic \
		QT_CFLAGS=-I"${LOCALBASE}/include/qt2" \
		QT_LIBS="-L${LOCALBASE}/lib -lqt2"
.else
CONFIGURE_ARGS+=--disable-djview
.endif

MAKE_ARGS+=	-j2

.if defined(LOCALBASE) && ${LOCALBASE} != "/usr/local"
pre-configure:
	${PERL} -pi -e 's,/usr/local,${LOCALBASE},g' `find ${WRKSRC} \
		-type f -print0 | xargs -0 ${GREP} -Fl --mmap /usr/local`
.endif

post-configure:
	${PERL} -pi -e 's,-O3,,;' -e 's,-mcpu=i386,,; ' \
		-e 's,^(OPTS =.*),\1 ${CFLAGS},' \
		${WRKSRC}/*/Makefile ${WRKSRC}/*/*/Makefile

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
