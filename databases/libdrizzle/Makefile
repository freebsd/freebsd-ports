PORTNAME=	libdrizzle
PORTVERSION=	0.8
PORTREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/41155299/ \
		LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client and protocol library for the Drizzle database
WWW=		https://launchpad.net/libdrizzle

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

OPTIONS_DEFINE=	DOXYGEN EXAMPLES
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
USES=		gmake libtool
CONFIGURE_ARGS+=--enable-libsqlite3
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	libdrizzle-redux # lib/libdrizzle.so

SAMPLE_PROGS=	client pipe_query proxy server simple \
		simple_multi sqlite_server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen>=0:devel/doxygen
ALL_TARGET=	all doxygen
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--disable-64bit
.elif ${ARCH:Mpowerpc*}
USES+=		compiler:gcc-c++11-lib
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
.for i in ${SAMPLE_PROGS}
	@${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
