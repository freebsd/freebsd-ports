# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	q4m
PORTVERSION=	0.9.14
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://q4m.kazuhooku.com/dist/
PKGNAMEPREFIX=	${_MYSQL_SERVER:T:C/-server$/-/}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Message queue that works as a pluggable storage engine of MySQL

FETCH_DEPENDS+=	${NONEXISTENT}:${_MYSQL_SERVER}:fetch
BUILD_DEPENDS+=	${NONEXISTENT}:${_MYSQL_SERVER}:build

USES=		gmake perl5 libtool
USE_MYSQL=	server
USE_GCC=	any
USE_PERL5=	run

GNU_CONFIGURE=	yes
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib/mysql
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--libdir="${PREFIX}/lib/mysql/plugin" \
		--with-mysql="$$(cd ${PORTSDIR}/${_MYSQL_SERVER}; ${MAKE} -V WRKSRC)" \
		CPPFLAGS="-I$$(cd ${PORTSDIR}/${_MYSQL_SERVER}; ${MAKE} -V BUILD_WRKSRC)/include -DDEBUG_OFF"
INSTALL_TARGET=	bindir=${STAGEDIR}${PREFIX}/bin install

post-extract:
	${CP} -p ${WRKSRC}/support-files/install.sql ${WRKSRC}/examples/

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	AUTHORS ChangeLog README doc
PORTEXAMPLES=	crawler install.sql

post-patch:
	@${REINPLACE_CMD} -e 's|/include/mysql|/include/mysql/mysql|g' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	cd ${WRKSRC}; ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples; ${COPYTREE_SHARE} ${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

install-functions:
	mysql -u root -p -f mysql < ${EXAMPLESDIR}/install.sql

test:
	cd ${WRKSRC}; ./run_tests.pl

.include <bsd.port.mk>
