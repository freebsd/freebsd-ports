# New ports collection makefile for:	ecore-file
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	file
PORTVERSION=	0.9.9.042
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (file module)

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_EFL=	ecore
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_file
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS=	--disable-ecore-con \
		--disable-ecore-config \
		--disable-ecore-desktop \
		--disable-ecore-directfb \
		--disable-ecore-evas \
		--enable-ecore-file \
		--disable-ecore-ipc \
		--disable-ecore-job \
		--disable-ecore-sdl \
		--disable-ecore-txt \
		--disable-ecore-x \
		--disable-ecore-imf \
		--disable-ecore-imf_evas

OPTIONS=	CURL	"Enable Curl support"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--enable-curl
LIB_DEPENDS+=		curl.4:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-file.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
