# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdrizzle
PORTVERSION=	0.8
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/41155299/ \
		LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Client and protocol library for the Drizzle database

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

OPTIONS_DEFINE=	DOXYGEN EXAMPLES DOCS

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix
CONFIGURE_ARGS+=--enable-libsqlite3
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

SAMPLE_PROGS=	client pipe_query proxy server simple \
		simple_multi sqlite_server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen>=0:devel/doxygen
ALL_TARGET=	all doxygen
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--disable-64bit
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
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
