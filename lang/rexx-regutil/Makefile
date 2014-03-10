# Created by: Bob Eager <bob@eager.cx>
# $FreeBSD$

PORTNAME=	regutil
PORTVERSION=	1.26
CATEGORIES=	lang
MASTER_SITES=	http://home.interlog.com/~ptjm/ http://www.tavi.co.uk/distfiles/
PKGNAMEPREFIX=	rexx-
DISTNAME=	regutil126

MAINTAINER=	bob@eager.cx
COMMENT=	An implementation of IBM's RexxUtil function library for Regina

BUILD_DEPENDS=	${LOCALBASE}/include/rexxsaa.h:${PORTSDIR}/lang/rexx-regina

USES=		zip

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_LDCONFIG=	yes
MAN1=		regutil.1
MLINKS=		regutil.1 rexxutil.1
MAKEFILE=	Makefile.bsd

SUB_FILES=	regutil.1 pkg-message

PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/librexxutil.so ${PREFIX}/lib
		${INSTALL_MAN} ${WRKDIR}/regutil.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/regutil.pdf ${DOCSDIR}
		@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
