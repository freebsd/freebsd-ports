# $FreeBSD$

PORTNAME=	libodbc++
PORTVERSION=	0.2.5
PORTREVISION=	0
CATEGORIES=	databases devel
MASTER_SITES=	SF/libodbcxx/libodbc%2B%2B/${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A C++ class library and toolset for ODBC access to data sources

LICENSE=	GPLv2

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-isqlxx
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
CXXFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_SINGLE=	ODBC
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC
OPTIONS_DEFAULT=	ODBC IODBC

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS=	libiodbc.so:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	progref

.if defined(NOPORTDOCS)
post-patch:
	${REINPLACE_CMD} '/^SUBDIRS/s/=.*/=/' ${WRKSRC}/doc/Makefile.in
.else
post-extract:
	${RM} -f ${WRKSRC}/doc/progref/progref-stamp
.endif

.include <bsd.port.mk>
