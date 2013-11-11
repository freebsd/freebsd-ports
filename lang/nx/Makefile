# Created by: gahr@FreeBSD.org
# $FreeBSD$

PORTNAME=	nx
DISTVERSION=	2.0b5
CATEGORIES=	lang
MASTER_SITES=	SF/next-scripting/${DISTVERSION}/
DISTNAME=	nsf${DISTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Highly flexible, Tcl-based, object-oriented scripting language

OPTIONS_DEFINE=	DOCS

LICENSE=	MIT

CONFLICTS=	xotcl-1.*

USES+=		tcl:85+
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
PLIST_SUB+=	PKGNAME=${DISTNAME}
PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	${CP} ${FILESDIR}/genStubs.tcl ${WRKSRC}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

regression-test: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
