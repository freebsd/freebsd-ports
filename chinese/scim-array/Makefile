# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	scim-array
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	http://of.openfoundry.org/download/scimarray/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Array 30 SCIM IMEngine module

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		gettext pkgconfig iconv

CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -e "s,@SCIM_MODULEDIR@,$$(pkg-config --variable=moduledir scim | ${SED} -e s,`pkg-config --variable=prefix scim`,${PREFIX},)," ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s,@SCIM_ICONDIR@,$$(pkg-config --variable=icondir scim | ${SED} -e s,`pkg-config --variable=prefix scim`,${PREFIX},)," ${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e "s,@SCIM_SHAREDIR@,$$(pkg-config --variable=scimdatadir scim | ${SED} -e s,`pkg-config --variable=prefix scim`,${PREFIX},)," ${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
