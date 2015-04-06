# $FreeBSD$

PORTNAME=	cego
PORTVERSION=	2.20.25
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Relational and transactional database system

LICENSE=	GPLv3

BUILD_DEPENDS=	liblfcbase.so>=1.5.11:${PORTSDIR}/devel/lfcbase
LIB_DEPENDS=	liblfcbase.so:${PORTSDIR}/devel/lfcbase \
		liblfcxml.so:${PORTSDIR}/devel/lfcxml

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

USE_LDCONFIG=	yes

USES=		ncurses readline libtool

USERS=	cego
GROUPS=	cego

PLIST_SUB+=	USER=${USERS}

post-patch:
	${REINPLACE_CMD} -e 's,-O3,,g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/samples/cgplustest/Makefile.in \
		${WRKSRC}/samples/cgwraptest/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/tools/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
	${REINPLACE_CMD} -e 's/%%USER%%/${USERS}/g' ${WRKSRC}/samples/rc/cego
	${CP} ${WRKSRC}/samples/rc/cego ${STAGEDIR}${PREFIX}/etc/rc.d/

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcego.so.1.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcgwrap.so.1.0.0

.include <bsd.port.mk>
