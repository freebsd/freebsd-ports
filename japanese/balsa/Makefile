# New ports collection makefile for:	ja-balsa
# Date created:				02 Mar 2000
# Whom:					Yoichi ASAI <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	balsa
PORTVERSION=	0.8.0
CATEGORIES=	japanese mail gnome
MASTER_SITES=	ftp://ftp.critical.ne.jp/pub/balsa-ja/
DISTNAME=	balsa-0.8.0-ja

MAINTAINER=	yatt@msc.biglobe.ne.jp

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList

WRKSRC=		${WRKDIR}/balsa-0.8.0ja

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
LIBTOOLFILES=	configure libmutt/configure
CONFIGURE_ARGS=	--enable-system-install --enable-threads
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		LIBS='-L${LOCALBASE}/lib'
MAN1=		balsa.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|\$\(gnomedatadir\)/gnome|\$\(gnomedatadir\)|g'

pre-configure:
	${RM} ${WRKSRC}/config.cache ${WRKSRC}/libmutt/config.cache

post-install:
	${INSTALL_MAN} ${WRKSRC}/balsa.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
