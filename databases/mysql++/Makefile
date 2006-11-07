# ports collection makefile for:	MySQL++
# Date created:				20th July 2000
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	mysql++
PORTVERSION=	2.1.1
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/
PKGNAMESUFFIX=	-mysql${MYSQL_VER}

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}

USE_MYSQL=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} --disable-examples
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

USE_GMAKE=      yes

CONFLICTS=	${PORTNAME}*-1.*

NOT_FOR_ARCHS=	amd64 sparc64
NOT_FOR_ARCHS_REASON_amd64=	Fails to compile
NOT_FOR_ARCHS_REASON_sparc64=	Fails to compile

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
USE_GCC=	3.4
.endif

post-install:
	@${RM} -f ${PREFIX}/lib/libmysqlpp.so.3
	@${LN} -s ${PREFIX}/lib/libmysqlpp.so ${PREFIX}/lib/libmysqlpp.so.3
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
