# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	libaura
PORTVERSION=	3.1.20051222
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	philip

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Library of Assorted Useful Reusable Abstractions

USE_BZIP2=	yes
USE_LDCONFIG=	yes

SONAME=		${SOLINK}.3
SOLINK=		${PORTNAME}3.so

PLIST_FILES=	lib/${SONAME} \
		lib/${SOLINK} \
		include/aura3/buffer.h \
		include/aura3/dict.h \
		include/aura3/popen.h \
		include/aura3/fspred.h \
		include/aura3/mem.h
PLIST_DIRS=	include/aura3
PORTDOCS=	README

MAKE_ENV=	SONAME=${SONAME} SOLINK=${SOLINK}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${SONAME} ${PREFIX}/lib/${SONAME}
	${LN} -s ${PREFIX}/lib/${SONAME} ${PREFIX}/lib/${SOLINK}
	${MKDIR} ${PREFIX}/include/aura3/
	${INSTALL_DATA} ${WRKSRC}/buffer.h ${PREFIX}/include/aura3/
	${INSTALL_DATA} ${WRKSRC}/dict.h ${PREFIX}/include/aura3/
	${INSTALL_DATA} ${WRKSRC}/popen.h ${PREFIX}/include/aura3/
	${INSTALL_DATA} ${WRKSRC}/fspred.h ${PREFIX}/include/aura3/
	${INSTALL_DATA} ${WRKSRC}/mem.h ${PREFIX}/include/aura3/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
