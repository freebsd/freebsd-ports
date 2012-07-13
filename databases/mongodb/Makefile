# New ports collection makefile for:  mongodb
# Date created:        3 November 2009
# Whom:                Mirko Zinn <mail@derzinn.de>
#
# $FreeBSD$
#

PORTNAME=	mongodb
PORTVERSION=	2.0.6
CATEGORIES=	databases net
MASTER_SITES=	http://downloads.mongodb.org/src/
DISTNAME=	${PORTNAME}-src-r${PORTVERSION}

MAINTAINER=	mail@derzinn.de
COMMENT=	A NOSQL distributed document-oriented database

LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		execinfo.1:${PORTSDIR}/devel/libexecinfo \
		nspr4:${PORTSDIR}/devel/nspr \
		pcre:${PORTSDIR}/devel/pcre \
		snappy:${PORTSDIR}/archivers/snappy

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than i386 and amd64"

OPTIONS_DEFINE=	DEVEL V8
DEVEL_DESC=	Install development files (library and headers)
V8_DESC=	Use v8 instead of spider monkey for javascript

USE_SCONS=	yes
SCONS_TARGET=	all
SCONS_ARGS=	--prefix=${PREFIX} --cxx=${CXX} --cpp=${CPP} --use-system-all

USERS=	mongodb
GROUPS=	mongodb

USE_RC_SUBR=	mongod

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEVEL}
SCONS_ARGS+=	--full
PLIST_SUB+=	DEVEL=""
.else
PLIST_SUB+=	DEVEL="@comment "
.endif

.if ${PORT_OPTIONS:MV8}
SCONS_ARGS+=	--usev8
LIB_DEPENDS+=	v8:${PORTSDIR}/lang/v8
.else
SCONS_ARGS+=	--usesm
LIB_DEPENDS+=	js:${PORTSDIR}/lang/spidermonkey
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/mongodb.conf ]; then \
		${TOUCH} ${PREFIX}/etc/mongodb.conf ; \
	fi

.include <bsd.port.mk>
