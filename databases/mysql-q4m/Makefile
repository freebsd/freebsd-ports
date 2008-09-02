# New ports collection makefile for:	Q4M
# Date created:		1 September 2008
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	q4m
PORTVERSION=	0.8.3
CATEGORIES=	databases
MASTER_SITES=	http://q4m.31tools.com/dist/
PKGNAMEPREFIX=	mysql${MYSQL_VER}-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A message queue that works as a pluggable storage engine of MySQL

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/databases/mysql${MYSQL_VER}-server:build \
		${LOCALBASE}/include/boost/spirit/core.hpp:${PORTSDIR}/devel/boost
RUN_DEPENDS=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql${MYSQL_VER}-server

USE_MYSQL=	yes
WANT_MYSQL_VER?=	51

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql"
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--libdir="${PREFIX}/lib/mysql/plugin" \
		--with-mysql="$$(cd ${PORTSDIR}/databases/mysql${MYSQL_VER}-server; ${MAKE} -V WRKSRC)"

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog README doc
PORTEXAMPLES=	examples support-files

post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	cd ${INSTALL_WRKSRC}; ${COPYTREE_SHARE} ${f} ${DOCSDIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${INSTALL_WRKSRC}; ${COPYTREE_SHARE} ${f} ${EXAMPLESDIR}
.endfor
	${RM} ${EXAMPLESDIR}/support-files/q4m-forward
.endif

test:
	cd ${BUILD_WRKSRC}; ${PERL} run_tests.pl

.include <bsd.port.mk>
