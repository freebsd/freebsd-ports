# New ports collection makefile for:	synfigstudio
# Date created:				25 Jun 2006
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	synfigstudio
DISTVERSION=	0.61.06
CATEGORIES=	graphics multimedia
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=synfig

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	Vector-based 2D animation software package

LIB_DEPENDS=	synfig.0:${PORTSDIR}/devel/synfig \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ETL.pc:${PORTSDIR}/devel/etl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gtk20 gnomehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

post-patch:
	@${REINPLACE_CMD} 's|TARGET_MNG="no"|TARGET_MNG="yes"|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
