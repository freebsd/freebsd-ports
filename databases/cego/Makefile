# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	cego
PORTVERSION=	2.19.2
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Relational and transactional database system

LICENSE=	GPLv3

LIB_DEPENDS=	lfcbase:${PORTSDIR}/devel/lfcbase \
		lfcxml:${PORTSDIR}/devel/lfcxml

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env
USE_RC_SUBR=	cego

USES=		ncurses readline

USERS=	cego
GROUPS=	cego

PLIST_SUB+=	USER=${USERS}

post-patch:
	@${REINPLACE_CMD} -e 's,-O3,,g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/samples/cgplustest/Makefile.in \
		${WRKSRC}/samples/cgwraptest/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/share/cego
	@${CP} ${WRKSRC}/tools/* ${PREFIX}/share/cego/

.include <bsd.port.mk>
