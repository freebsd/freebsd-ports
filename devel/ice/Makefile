# New ports collection makefile for:	ice
# Date created:		2004-02-02
# Whom:			Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	Ice
PORTVERSION=	3.2.1
CATEGORIES=	devel
MASTER_SITES=	http://www.zeroc.com/download/Ice/3.2/

MAINTAINER=	shoesoft@gmx.net
COMMENT=	A modern alternative to object middleware such as CORBA/COM/DCOM/COM+

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
USE_BDB=	42+
INVALID_BDB_VER=	2 3 40 41
USE_LDCONFIG=	yes

CFLAGS+=	-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT ${PTHREAD_CFLAGS}
.if defined(DEBUG)
CFLAGS+=	-g
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>
.if ${ARCH} == "ia64"
BROKEN=		does not compile on ia64
.endif

.if ${ARCH} == "sparc64"
BROKEN=		fails to link
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=	LP64=yes
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

post-patch:
	${SED} 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g; \
		s|%%PREFIX%%|${PREFIX}|g; \
		s|%%DATADIR%%|${DATADIR}|g; \
		s|%%DOCSDIR%%|${DOCSDIR}|g; \
		s|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g' \
		${FILESDIR}/Make.rules.FreeBSD > ${WRKSRC}/config/Make.rules.FreeBSD
	${REINPLACE_CMD} 's|%%BDB_LIB_CXX_NAME%%|${BDB_LIB_CXX_NAME}|g; \
		s|%%BDB_LIB_DIR%%|${BDB_LIB_DIR}|g; \
		s|%%BDB_INCLUDE_DIR%%|${BDB_INCLUDE_DIR}|g' \
		${WRKSRC}/config/Make.rules
	${REINPLACE_CMD} 's|prefix|install_slicedir|g' ${WRKSRC}/config/Makefile
	${REINPLACE_CMD} 's|prefix|install_slicedir|g; \
		s|INSTALL_PROGRAM|INSTALL_DATA|g' ${WRKSRC}/src/ca/Makefile
	${FIND} ${WRKSRC} -name Makefile -exec ${REINPLACE_CMD} 's|-lIceSSL|-lIceSSL -lIceXML|' {} \;

.include <bsd.port.post.mk>
