# ports collection makefile for:	MySQL++
# Date created:				2008-04-03
# Whom:					Vlad GALU <dudu@dudu.ro>
#
# $FreeBSD$
#

PORTNAME=	mysql++
PORTVERSION=	3.0.8
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/ \
		T32.TecNik93.com/ports/others_ports/${PORTNAME}/sources/
PKGNAMESUFFIX=	-mysql${MYSQL_VER}

MAINTAINER=	dudu@dudu.ro
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}

USE_MYSQL=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE} --enable-thread-check
USE_LDCONFIG=	yes
USE_GMAKE=	yes
PLIST_SUB+=	VER=${PORTVERSION}

CONFLICTS=	${PORTNAME}*-1.*

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} pdf ${DOCSDIR})
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif
.ifndef(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.h ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cpp ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
