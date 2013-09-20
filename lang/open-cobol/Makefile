# Created by: ijliao
# $FreeBSD$

PORTNAME=	open-cobol
PORTVERSION=	1.1
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	An open-source COBOL compiler

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

USE_BDB=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

INFO=		open-cobol

CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include  <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|__gmp_randinit|__gmpz_init|g ; \
		 s|db-4.[0-9]|${BDB_LIB_NAME}|g' ${WRKSRC}/configure

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${WRKSRC}/tests;	\
	./syntax;		\
	./run)
.endif

.include <bsd.port.mk>
