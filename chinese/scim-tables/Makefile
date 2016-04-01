# Created by: Jie Gao	<gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	scim-tables
PORTVERSION=	0.5.10
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM table based Chinese input methods

BUILD_DEPENDS=	scim:textproc/scim \
		scim-make-table:textproc/scim-table-imengine
RUN_DEPENDS=	scim-make-table:textproc/scim-table-imengine

USES=		pkgconfig gmake
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__

CONFIGURE_ENV+=	SCIM_DATADIR=${PREFIX}/share/scim \
		SCIM_ICONDIR=${PREFIX}/share/scim/icons
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

CONFIGURE_ARGS+=	--disable-skim-support

.include <bsd.port.post.mk>
