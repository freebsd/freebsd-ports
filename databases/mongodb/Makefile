# New ports collection makefile for:  mongodb
# Date created:        3 November 2009
# Whom:                Mirko Zinn <mail@derzinn.de>
#
# $FreeBSD$
#

PORTNAME=	mongodb
PORTVERSION=	1.2.0
CATEGORIES=	databases net
MASTER_SITES=	http://downloads.mongodb.org/src/ \
		http://derzinn.de/files/
DISTNAME=	mongodb-src-r${PORTVERSION}

MAINTAINER=	mail@derzinn.de
COMMENT=	A NOSQL distributed document-oriented database

LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		js:${PORTSDIR}/lang/spidermonkey \
		pcre:${PORTSDIR}/devel/pcre \
		nspr4:${PORTSDIR}/devel/nspr \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

CONFLICTS=	mongodb-devel-[0-9]*

USE_SCONS=	yes
SCONS_TARGET=	all

USE_RC_SUBR=	mongod
MONGO_FILES=	mongo mongod mongodump mongoexport mongofiles \
		mongoimport mongorestore mongos mongosniff

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 700042
BROKEN=		Does not build
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|elif "freebsd7" == os.sys.platform|elif os.sys.platform.startswith("freebsd")|' \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's#/usr/local#${PREFIX}#g' ${WRKSRC}/SConstruct

do-install:
.for i in ${MONGO_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/libmongoclient.a ${PREFIX}/lib

post-install:
	@if [ ! -f ${PREFIX}/etc/mongodb.conf ]; then \
		${TOUCH} ${PREFIX}/etc/mongodb.conf ; \
	fi

	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.post.mk>
