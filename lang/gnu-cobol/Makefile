# Created by: ijliao
# $FreeBSD$

PORTNAME=	gnu-cobol
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	GNU/gnucobol

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Open-source COBOL compiler

LIB_DEPENDS=	libgmp.so:math/gmp

USE_BDB=	yes
USES=		gmake libtool ncurses
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INFO=		gnu-cobol

CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
CONFIGURE_ENABLE=nls

post-patch:
	@${REINPLACE_CMD} -e 's|__gmp_randinit|__gmpz_init|g ; \
		 s|db-4.[0-9]|${BDB_LIB_NAME}|g ; \
		 s|-lcurses|-lncurses|g ; \
		 s|-R$$found_dir|-Wl,-rpath,$$found_dir|g' ${WRKSRC}/configure

.include <bsd.port.mk>
