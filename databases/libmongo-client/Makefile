# Created by: Denis Generalov <gd@rambler-co.ru>
# $FreeBSD$

PORTNAME=	libmongo-client
PORTVERSION=	0.1.6.3
CATEGORIES=	databases

MAINTAINER=	gd@rambler-co.ru
COMMENT=	Alternative C driver for MongoDB

LICENSE=	AL2

USE_GITHUB=	yes
GH_ACCOUNT=	algernon
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
GH_COMMIT=	ff123ed # should be 9cbb488, but does not

USE_AUTOTOOLS=	automake autoconf libtool
GNU_CONFIGURE=	yes
USES=		pkgconfig gmake
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	PKG_CONFIG_DIR=${LOCALBASE}/libdata/pkgconfig

NO_STAGE=	yes
run-autotools:
	@${REINPLACE_CMD} 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/src/Makefile.am
	@cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -i

.include <bsd.port.mk>
