# $FreeBSD$

PORTNAME=	libodbc++
PORTVERSION=	0.2.5
PORTREVISION=	3
CATEGORIES=	databases devel
MASTER_SITES=	SF/libodbcxx/libodbc%2B%2B/${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	C++ class library and toolset for ODBC access to data sources

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOXYGEN

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

USES=		gmake libtool ncurses pathfix pkgconfig readline tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-isqlxx
INSTALL_TARGET=	install-strip

LIB_DEPENDS=	libodbc.so:databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	progref

post-extract:
	${RM} ${WRKSRC}/doc/progref/progref-stamp

post-patch:
	@${REINPLACE_CMD} -e 's|-ltermcap|-lncurses|' ${WRKSRC}/configure

.include <bsd.port.mk>
