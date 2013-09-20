# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	q4m
PORTVERSION=	0.9.5
CATEGORIES=	databases
MASTER_SITES=	http://q4m.kazuhooku.com/dist/
PKGNAMEPREFIX=	mysql${MYSQL_VER}-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A message queue that works as a pluggable storage engine of MySQL

FETCH_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/databases/mysql${MYSQL_VER}-server:build
RUN_DEPENDS=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql${MYSQL_VER}-server

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_MYSQL=	yes
WANT_MYSQL_VER?=	51

GNU_CONFIGURE=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--libdir="${PREFIX}/lib/mysql/plugin" \
		--with-mysql="$$(cd ${PORTSDIR}/databases/mysql${MYSQL_VER}-server; ${MAKE} -V WRKSRC)"

COPYTREE_AUTO=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
					2>&1) && \
					${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$1 && \
					${FIND} $$1 -type d -exec chmod 755 {} \; && \
					${FIND} $$1 -type f \! -perm +100 -exec chmod ${SHAREMODE} {} \; && \
					${FIND} $$1 -type f -perm +100 -exec ${CHOWN} ${BINOWN}:${BINGRP} {} \; && \
					${FIND} $$1 -type f -perm +100 -exec chmod ${BINMODE} {} \;' --

NO_STAGE=	yes
post-extract:
	${CP} -p ${WRKSRC}/support-files/install.sql ${WRKSRC}/examples/

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog README doc
PORTEXAMPLES=	crawler install.sql

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	cd ${WRKSRC}; ${COPYTREE_SHARE} ${f} ${DOCSDIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples; ${COPYTREE_AUTO} ${f} ${EXAMPLESDIR}
.endfor
.endif

install-functions:
	mysql -u root -f mysql < ${EXAMPLESDIR}/install.sql

test:
	cd ${WRKSRC}; ${PERL} run_tests.pl

.include <bsd.port.mk>
