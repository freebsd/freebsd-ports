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

		-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 701000
post-patch:
	${REINPLACE_CMD} -e 's|-lrt||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.include <bsd.port.post.mk>
