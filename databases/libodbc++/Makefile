PORTNAME=	libodbc++
PORTVERSION=	0.2.5
PORTREVISION=	5
CATEGORIES=	databases devel
MASTER_SITES=	SF/libodbcxx/libodbc%2B%2B/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library and toolset for ODBC access to data sources
WWW=		http://orcane.net/freeodbc++/

LICENSE=	GPLv2

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		gmake libtool ncurses pkgconfig readline tar:bzip2
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-isqlxx --with-odbc=${LOCALBASE}

INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	progref

OPTIONS_DEFINE=	DOXYGEN DOCS

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-extract:
	${RM} ${WRKSRC}/doc/progref/progref-stamp

post-patch:
	@${REINPLACE_CMD} -e 's|-ltermcap|-lncurses|' ${WRKSRC}/configure

.include <bsd.port.mk>
