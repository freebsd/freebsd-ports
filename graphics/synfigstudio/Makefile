# New ports collection makefile for:	synfigstudio
# Date created:				25 Jun 2006
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	synfigstudio
DISTVERSION=	0.62.01
CATEGORIES=	graphics multimedia
MASTER_SITES=	SF/synfig/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Vector-based 2D animation software package

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ETL.pc:${PORTSDIR}/devel/etl
LIB_DEPENDS=	synfig.0:${PORTSDIR}/devel/synfig \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GNOME=	gnomehack gnometarget gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} '/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=|' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
