# New ports collection makefile for:	chmsee
# Date created:                		10 June 2006
# Whom:                    		Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	chmsee
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A viewer for Microsoft Help "CHM" files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib \
		gcrypt.17:${PORTSDIR}/security/libgcrypt

USE_GNOME=	gnomehier libglade2
USE_GECKO=	libxul seamonkey
USE_GETTEXT=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

MAN1=		chmsee.1

.include <bsd.port.pre.mk>

.if defined(GECKO) && ${GECKO:Mlibxul}!=""
GTKMOZEMBED_LIB="${GECKO}-embedding-unstable nspr"
.else
GTKMOZEMBED_LIB="${GECKO}-gtkmozembed"
CFLAGS+=	-I${LOCALBASE}/include/${GECKO}/commandhandler \
		-I${LOCALBASE}/include/${GECKO}/locale \
		-DGECKO_LIB_ROOT="\\\"\"${LOCALBASE}/lib/${GECKO}\"\\\""
.endif

post-extract:
	@(cd ${WRKSRC}/data; ${CP} -f chmsee.desktop.in chmsee.desktop.skel)

post-patch:
	@${REINPLACE_CMD} -e \
		'/REQUIRED/s|libxul-.*=1.9.0.999|${GTKMOZEMBED_LIB}|g ; \
		 /FLAVOUR/s|libxul|${GECKO}|g' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|.desktop.in|.desktop.skel|g' ${WRKSRC}/data/CMakeLists.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/chmsee.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
