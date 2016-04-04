# Created by: Bob Eager <bob@eager.cx>
# $FreeBSD$

PORTNAME=	regutil
PORTVERSION=	1.26
CATEGORIES=	lang
MASTER_SITES=	http://home.interlog.com/~ptjm/ http://www.tavi.co.uk/distfiles/
PKGNAMEPREFIX=	rexx-
DISTNAME=	regutil126

MAINTAINER=	bob@eager.cx
COMMENT=	Implementation of IBM's RexxUtil function library for Regina

BUILD_DEPENDS=	${LOCALBASE}/include/rexxsaa.h:lang/rexx-regina

USES=		ncurses zip

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_LDCONFIG=	yes
MAKEFILE=	Makefile.bsd
MAKE_ARGS+=	PLIBS="${LDFLAGS:M-L*} -lncurses"

SUB_FILES=	regutil.1 pkg-message

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

do-install:
		${INSTALL_LIB} ${WRKSRC}/librexxutil.so ${STAGEDIR}${PREFIX}/lib
		${INSTALL_MAN} ${WRKDIR}/regutil.1 ${STAGEDIR}${PREFIX}/man/man1/regutil.1.gz
		${INSTALL_MAN} ${WRKDIR}/regutil.1 ${STAGEDIR}${PREFIX}/man/man1/rexxutil.1.gz

post-install:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/regutil.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
