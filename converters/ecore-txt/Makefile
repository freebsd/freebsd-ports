# New ports collection makefile for:	ecore-txt
# Date created:				22 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	txt
PORTVERSION=	0.9.9.042
PORTREVISION=	0
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (txt module)

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_EFL=	ecore
USE_ICONV=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_txt
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS=	--disable-ecore-con \
		--disable-ecore-config \
		--disable-ecore-desktop \
		--disable-ecore-directfb \
		--disable-ecore-evas \
		--disable-ecore-file \
		--disable-ecore-ipc \
		--disable-ecore-job \
		--disable-ecore-sdl \
		--enable-ecore-txt \
		--disable-ecore-x \
                --disable-ecore-imf \
		--disable-ecore-imf_evas

post-patch:
	@${REINPLACE_CMD} -E -e \
		's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-txt.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
