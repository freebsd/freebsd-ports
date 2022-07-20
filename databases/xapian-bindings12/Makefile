PORTNAME=	xapian-bindings
PORTVERSION=	1.2.25
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxapian.so:databases/xapian-core12

USES=		libtool tar:xz

CONFIGURE_ARGS=	--datarootdir=${DATADIR} --docdir=${DOCSDIR} \
		--without-csharp --without-java --without-perl --without-ruby --without-tcl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

CONFLICTS=	xapian-bindings

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS LUA

LUA_CONFIGURE_ENV=	LUA="${LUA_CMD}" LUA_INC="${LUA_INCDIR}" LUA_LIB="${LUA_MODLIBDIR}" LUA_SO=.so
LUA_CONFIGURE_WITH=	lua
LUA_PLIST_FILES=	${LUA_MODLIBDIR}/xapian.so
LUA_USES=		lua

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' ${WRKSRC}/configure

.include <bsd.port.mk>
