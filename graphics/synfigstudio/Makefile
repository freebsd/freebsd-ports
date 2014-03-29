# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfigstudio
DISTVERSION=	0.63.05
PORTREVISION=	1
CATEGORIES=	graphics multimedia
MASTER_SITES=	SF/synfig/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Vector-based 2D animation software package

BROKEN=		Fails to compile

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ETL.pc:${PORTSDIR}/devel/etl
LIB_DEPENDS=	synfig.0:${PORTSDIR}/devel/synfig \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GNOME=	gnomehack gtk20
USES=		gettext
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=|' -e \
		's|sk_SK|sk|g' ${WRKSRC}/configure

# FIX LC_MESSAGES
	${MV} ${WRKSRC}/po/sk_SK.gmo ${WRKSRC}/po/sk.gmo

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
