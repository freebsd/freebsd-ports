# $FreeBSD$

PORTNAME=	cego
PORTVERSION=	2.39.8
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Relational and transactional database system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblfcbase.so:devel/lfcbase \
		liblfcxml.so:devel/lfcxml
RUN_DEPENDS=	${LOCALBASE}/bin/sudo:security/sudo \
		bash:shells/bash

USES=		libtool localbase ncurses readline shebangfix
SHEBANG_FILES=	tools/cgbackup tools/cgrecover tools/cgsimload \
		tools/logManager tools/backupManager
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
TEST_TARGET=	check

USERS=		cego
GROUPS=		cego

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

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcego.so.2.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcgwrap.so.2.0.0

.include <bsd.port.mk>
