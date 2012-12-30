# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	cego
PORTVERSION=	2.15.3
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Relational and transactional database system

LICENSE=	GPLv2

LIB_DEPENDS=	lfc:${PORTSDIR}/devel/lfc \
		lfcxml:${PORTSDIR}/devel/lfcxml

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env
USE_RC_SUBR=	cego

USE_NCURSES=	yes
USE_READLINE=	yes

USERS=	cego
GROUPS=	cego

PLIST_SUB+=	USER=${USERS}

post-patch:
	@${REINPLACE_CMD} -e 's,-O3,,g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/samples/cgplustest/Makefile.in \
		${WRKSRC}/samples/cgwtest/Makefile.in

.include <bsd.port.mk>
