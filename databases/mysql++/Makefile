# ports collection makefile for:	MySQL++
# Date created:				20th July 2000
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	mysql++
PORTVERSION=	2.0.7
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/
PKGNAMESUFFIX=	-mysql${MYSQL_VER}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USE_MYSQL=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} --disable-examples
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

CONFLICTS=	${PORTNAME}*-1.*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
USE_GCC=	3.4
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/userman/html ${DOCSDIR}/refman/html
	@${INSTALL_DATA} ${WRKSRC}/doc/userman/html/* ${DOCSDIR}/userman/html
	@${INSTALL_DATA} ${WRKSRC}/doc/refman/html/* ${DOCSDIR}/refman/html
	@${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.cpp ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.h ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/Makefile.simple ${EXAMPLESDIR}/Makefile.temp
	@${SED} -e "s|-I../lib|-I${PREFIX}/include/mysql++|" < ${EXAMPLESDIR}/Makefile.temp | \
		${SED} -e "s|/usr/include/mysql|${LOCALBASE}/include/mysql|" | \
		${SED} -e "s|CXX=g++||" | \
		${SED} -e "s|-lmysqlpp|-L${PREFIX}/lib -L${LOCALBASE}/lib/mysql -lmysqlpp|" \
		> ${EXAMPLESDIR}/Makefile
	@${RM} -f ${EXAMPLESDIR}/Makefile.temp
.endif

.include <bsd.port.post.mk>
