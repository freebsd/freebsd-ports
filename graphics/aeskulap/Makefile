# New ports collection Makefile for:	aeskulap
# Date created:				21 July 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	aeskulap
PORTVERSION=	0.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.bms-austria.com/%7Epipelka/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A medical image viewer

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
    		glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		gconfmm-2.6:${PORTSDIR}/devel/gconfmm26 \
		dcmdata.3:${PORTSDIR}/devel/dcmtk

USE_GETTEXT=	yes
USE_GNOME=	gconf2
GCONF_SCHEMAS=	aeskulap.schemas
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

CXXFLAGS+=	-fPIC \
		-I${LOCALBASE}/include/dcmtk \
		-I${LOCALBASE}/include/dcmtk/config \
		-I${LOCALBASE}/include/dcmtk/ofstd \
		-I${LOCALBASE}/include/dcmtk/dcmdata \
		-I${LOCALBASE}/include/dcmtk/dcmnet \
		-I${LOCALBASE}/include/dcmtk/dcmjpeg \
		-I${LOCALBASE}/include/dcmtk/dcmimage \
		-I${LOCALBASE}/include/dcmtk/dcmimgle \
		-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not link on 6.X
.endif

.include <bsd.port.post.mk>
