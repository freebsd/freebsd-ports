# Created by: gahr@FreeBSD.org
# $FreeBSD$

PORTNAME=	nx
DISTVERSION=	2.0.0
CATEGORIES=	lang
MASTER_SITES=	SF/next-scripting/${DISTVERSION}/
DISTNAME=	nsf${DISTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Highly flexible, Tcl-based, object-oriented scripting language

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

CONFLICTS=	xotcl-1.*

USES+=		gmake tcl:85+
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
TEST_TARGET=	test
PLIST_SUB+=	PKGNAME=${DISTNAME}
PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/lib${DISTNAME}.so

.include <bsd.port.mk>
