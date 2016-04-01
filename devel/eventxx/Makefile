# Created by: ijliao
# $FreeBSD$

PORTNAME=	eventxx
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://proj.llucax.com.ar/home/eventxx/releases/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper for libevent

LIB_DEPENDS=	libevent.so:devel/libevent2

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	@${REINPLACE_CMD} -e 's|-I..|-I.. -I${LOCALBASE}/include -L${LOCALBASE}/lib|g' \
	    ${WRKSRC}/test/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/eventxx ${STAGEDIR}${PREFIX}/include
	${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/test && ${COPYTREE_SHARE} \*.cpp ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/Makefile ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
