# New ports collection makefile for:	ocaml libevent
# Date created:		Thu Aug 25 15:34:53 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	event
PORTVERSION=	0.5.0
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://www.xs4all.nl/~mmzeeman/ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ocaml wrapper for the libevent API

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

ALL_TARGET=	all allopt
USE_GMAKE=	yes

.ifndef(NOPORTDOCS)
ALL_TARGET+=	doc

PORTDOCS=	*
.endif

EXAMPLE_FILES=	\
		Makefile \
		fifo_example.ml \
		signal_example.ml
LIB_FILES=	\
		libevent.a \
		libevent.cmxa \
		libmlevent.a \
		libevent.cma \
		libevent.mli \
		libevent.cmi
LIB_STUB_FILES=	\
		dllmlevent.so

# examples to install
PLIST_DIRS+=	${EXAMPLESDIR:S,^${PREFIX}/,,}
.for file in ${EXAMPLE_FILES}
PLIST_FILES+=	${EXAMPLESDIR:S,^${PREFIX}/,,}/${file}
.endfor
# libraries to install
.for file in ${LIB_FILES}
PLIST_FILES+=	lib/ocaml/${file}
.endfor
.for file in ${LIB_STUB_FILES}
PLIST_FILES+=	lib/ocaml/stublibs/${file}
.endfor

post-configure:
# CFLAGS, LOCALBASE safeness
	${REINPLACE_CMD} -E -e \
		's|^(EVENT_LIB=).*$$|\1-levent|; \
		s|^EVENT_LIBDIR=.*$$|EVENT_LIBDIR=${LOCALBASE}/lib|;  \
		s|^EVENT_INCDIR=.*$$|EVENT_INCDIR=${LOCALBASE}/include|; \
		s|^(CFLAGS).*$$|\1=${CFLAGS} -I\$$(EVENT_INCDIR)|' \
		${WRKSRC}/Makefile

pre-build:
.for file in libevent.cmi
	@cd ${WRKSRC} && ${GMAKE} ${file}
.endfor

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
# examples
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
# libs
	@${MKDIR} ${PREFIX}/lib/ocaml/stublibs
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/ocaml
.endfor
.for file in ${LIB_STUB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/ocaml/stublibs
.endfor

.include <bsd.port.pre.mk>

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.post.mk>
