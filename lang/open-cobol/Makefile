# ex:ts=8
# Ports collection makefile for:	open-cobol
# Date created:			Aug 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	open-cobol
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	glen.j.barber@gmail.com
COMMENT=	An open-source COBOL compiler

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

CONFLICTS=	open-cobol-1.[1]*

USE_GNOME=	gnometarget
USE_BDB=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

INFO=		open-cobol

CPPFLAGS=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
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
