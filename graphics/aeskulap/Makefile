# New ports collection Makefile for:	aeskulap
# Date created:				21 July 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	aeskulap
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.bms-austria.com/%7Epipelka/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A medical image viewer

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
    		glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		gconfmm-2.6:${PORTSDIR}/devel/gconfmm26

USE_GETTEXT=	yes
USE_GNOME=	gconf2
GCONF_SCHEMAS=	aeskulap.schemas
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

CXXFLAGS+=	-fPIC \
		-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 701000
PLIST_SUB=	SHVER=""
post-install:
	${LN} -s libimagepool.so.0.0 ${PREFIX}/lib/aeskulap/libimagepool.so
	${LN} -s libconfiguration.so.0.0 ${PREFIX}/lib/aeskulap/libconfiguration.so
.else
PLIST_SUB=	SHVER="@comment "
post-patch:
	${REINPLACE_CMD} -e 's|-lrt||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.include <bsd.port.post.mk>
