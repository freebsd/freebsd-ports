# New ports collection makefile for:	libdrizzle
# Date created:		2010-03-03
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdrizzle
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/41155299/ \
		LOCAL/glarkin

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Client and protocol library for the Drizzle database

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

OPTIONS=	DOCS "Build documentation with doxygen" Off

USE_GCC=	4.2+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-libsqlite3
USE_GMAKE=	yes
USE_LDCONFIG=	yes

SAMPLE_PROGS=	client pipe_query proxy server simple \
		simple_multi sqlite_server

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
.if defined(WITH_DOCS)
BUILD_DEPENDS+=	doxygen>=0:${PORTSDIR}/devel/doxygen
ALL_TARGET=	all doxygen
PLIST_SUB+=	PORTDOCS=""

post-install::
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif
.endif

.if !defined(NOPORTEXAMPLES)
post-install::
	@${INSTALL} -d ${EXAMPLESDIR}
.for i in ${SAMPLE_PROGS}
	@${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${i} ${EXAMPLESDIR}
.endfor
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--disable-64bit
.endif

.include <bsd.port.post.mk>
