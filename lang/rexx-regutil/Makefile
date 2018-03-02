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

LICENSE=	MPL10

BUILD_DEPENDS=	${LOCALBASE}/include/rexxsaa.h:lang/rexx-regina

USES=		ncurses zip

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes	# lld lacks built-in search paths
MAKEFILE=	Makefile.bsd
MAKE_ARGS+=	PLIBS="${LDFLAGS:M-L*} -lncurses"
CFLAGS+=	-D_WANT_SEMUN

SUB_FILES=	regutil.1

PLIST_FILES=	lib/librexxutil.so \
		man/man1/regutil.1.gz

PORTDOCS=	regutil.pdf
PORTEXAMPLES=	*.rex

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_LIB} ${WRKSRC}/librexxutil.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKDIR}/regutil.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/regutil.pdf ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rex ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
