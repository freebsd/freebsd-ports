# $FreeBSD$

PORTNAME=	libodbc++
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	SF/libodbcxx/libodbc%2B%2B/${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	C++ class library and toolset for ODBC access to data sources

LICENSE=	GPLv2

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

OPTIONS_DEFINE=	DOCS

USES=		gmake libtool pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-isqlxx
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
CXXFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	progref

post-extract:
	${RM} -f ${WRKSRC}/doc/progref/progref-stamp

.include <bsd.port.mk>
