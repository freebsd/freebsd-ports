# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	file
PORTVERSION=	1.7.9
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	ecore-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (file module)

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	ecore libtool_hack
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_file
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../ecore-main/Makefile.inc"

CONFIGURE_ARGS+=--enable-ecore-file

OPTIONS_DEFINE=	CURL
OPTIONS_DEFAULT=CURL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
USE_EFL_ECORE=	con
CONFIGURE_ARGS+=--enable-ecore-con \
		--enable-curl
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=--disable-curl
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		${BUILD_WRKSRC}/Makefile.in
.if !defined(WITHOUT_CURL)
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore_con/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_con/libecore_con\.la,-lecore_con,'\
		${BUILD_WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-file.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
