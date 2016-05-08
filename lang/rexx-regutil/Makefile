# Created by: Bob Eager <bob@eager.cx>
# $FreeBSD$

PORTNAME=	regutil
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://home.interlog.com/~ptjm/ \
		http://www.ancientgeek.org.uk/distfiles/
PKGNAMEPREFIX=	rexx-
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	bob@eager.cx
COMMENT=	Implementation of IBM's RexxUtil function library for Regina

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/include/rexxsaa.h:lang/rexx-regina

USES=		ncurses zip

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_LDCONFIG=	yes
MAKEFILE=	Makefile.bsd
MAKE_ARGS+=	PLIBS="${LDFLAGS:M-L*} -lncurses"

SUB_FILES=	regutil.1

PLIST_FILES=	lib/librexxutil.so \
		man/man1/regutil.1.gz

PORTDOCS=	regutil.pdf
PORTEXAMPLES=	*.rex

OPTIONS_DEFINE=	DOCS EXAMPLES

#include <bsd.options.mk>

do-install:
		${INSTALL_LIB} ${WRKSRC}/librexxutil.so ${STAGEDIR}${PREFIX}/lib/
		${INSTALL_MAN} ${WRKDIR}/regutil.1 ${STAGEDIR}${PREFIX}/man/man1/

do-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/regutil.pdf ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_MAN} ${WRKSRC}/*.rex ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
