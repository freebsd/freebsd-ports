# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	scim-array
PORTVERSION=	1.0.1
PORTREVISION=	8
CATEGORIES=	chinese
MASTER_SITES=	http://of.openfoundry.org/download/scimarray/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Array 30 SCIM IMEngine module

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	scim:textproc/scim
RUN_DEPENDS=	scim:textproc/scim

GNU_CONFIGURE=	yes
USES=		gettext gmake iconv libtool:keepla pkgconfig
INSTALL_TARGET=	install-strip

CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include

pre-configure:
	@${REINPLACE_CMD} -e "s,@SCIM_MODULEDIR@,$$(pkg-config --variable=moduledir scim | ${SED} -e s,`pkg-config --variable=prefix scim`,${PREFIX},)," ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s,@SCIM_ICONDIR@,$$(pkg-config --variable=icondir scim | ${SED} -e s,`pkg-config --variable=prefix scim`,${PREFIX},)," ${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e "s,@SCIM_SHAREDIR@,$$(pkg-config --variable=scimdatadir scim | ${SED} -e s,`pkg-config --variable=prefix scim`,${PREFIX},)," ${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
