# Created by: dd
# $FreeBSD$

PORTNAME=	nvi
PORTVERSION=	1.81.6
PORTREVISION=	9
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/nvi/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Development snapshot of the world-renown nvi editor

CONFLICTS_INSTALL=	nvi-m17n-[0-9]* xnview-[0-9]*

OPTIONS_DEFINE=	WIDECHAR
OPTIONS_DEFAULT=WIDECHAR
WIDECHAR_DESC=	Enable wide-character support (UTF-8)

WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
USES=			bdb iconv libtool ncurses pkgconfig tar:bzip2
CONFIGURE_ARGS+=	--with-db-prefix=${LOCALBASE} \
			--program-prefix=n
CONFIGURE_SCRIPT=	../dist/configure

WIDECHAR_CONFIGURE_ON=	--enable-widechar

CPPFLAGS+=		-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include -I${NCURSESINC}
LDFLAGS+=		-L${BDB_LIB_DIR} -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/libvi_la_LIBADD =/s,$$, ${ICONV_LIB},' \
		${WRKSRC}/../dist/Makefile.in
	@${REINPLACE_CMD} -e 's,-ldb,-l${BDB_LIB_NAME},g' \
		${WRKSRC}/../dist/configure

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/man/cat1/*.0

.include <bsd.port.mk>
