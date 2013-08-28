# Created by: chinsan
# $FreeBSD$

PORTNAME=	paexec
PORTVERSION=	0.19.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Parallel executor, distributes tasks over network

LICENSE=	MIT

BUILD_DEPENDS=	mkcmake:${PORTSDIR}/devel/mk-configure \
		runawk:${PORTSDIR}/lang/runawk
LIB_DEPENDS=	libmaa.so:${PORTSDIR}/devel/libmaa

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		perl5
USE_PERL5=	build
MAKE_ENV=	SUBPRJ_DFLT="${SUBPRJ_DFLT}"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		${PORTNAME}.1 \
		${PORTNAME}_reorder.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}_reorder

SUBPRJ_DFLT=	${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
SUBPRJ_DFLT+=	doc
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
SUBPRJ_DFLT+=	examples
MAKE_ENV+=	EGDIR="${EXAMPLESDIR}"
.endif

do-build:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC}

do-install:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC} \
		${INSTALL_TARGET}

.include <bsd.port.mk>
