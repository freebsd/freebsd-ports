# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdrizzle
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/41155299/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client and protocol library for the Drizzle database

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

OPTIONS_DEFINE=	DOXYGEN EXAMPLES

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-libsqlite3
USE_GMAKE=	yes
USE_LDCONFIG=	yes

SAMPLE_PROGS=	client pipe_query proxy server simple \
		simple_multi sqlite_server

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEB}
BUILD_DEPENDS+=	doxygen>=0:${PORTSDIR}/devel/doxygen
ALL_TARGET=	all doxygen
PLIST_SUB+=	PORTDOCS=""

post-install::
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
post-install::
	@${INSTALL} -d ${EXAMPLESDIR}
.for i in ${SAMPLE_PROGS}
	@${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${i} ${EXAMPLESDIR}
.endfor
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--disable-64bit
.endif

.include <bsd.port.mk>
