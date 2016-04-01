# Created by: Jie Gao	<gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	scim-tables
PORTVERSION=	0.5.10
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM table based Japanese input methods

BUILD_DEPENDS=	scim:textproc/scim \
		scim-make-table:textproc/scim-table-imengine
RUN_DEPENDS=	scim-make-table:textproc/scim-table-imengine

USES=		pkgconfig gmake
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__

CONFIGURE_ENV+=	SCIM_DATADIR=${PREFIX}/share/scim \
		SCIM_ICONDIR=${PREFIX}/share/scim/icons
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

CONFIGURE_ARGS+=	--disable-skim-support

post-extract:
	@${CP} ${FILESDIR}/T-Code.txt.in   ${WRKSRC}/tables/ja/
	@${CP} ${FILESDIR}/TUT-Code.txt.in ${WRKSRC}/tables/ja/

.include <bsd.port.mk>
