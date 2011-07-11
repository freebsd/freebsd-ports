# New ports collection makefile for:	paexec
# Date created:				2008/01/26
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	paexec
PORTVERSION=	0.16.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Parallel executor, distributes tasks over network

LICENSE=	MIT

LIB_DEPENDS=	maa:${PORTSDIR}/devel/libmaa
BUILD_DEPENDS=	mk-configure>=0.20:${PORTSDIR}/devel/mk-configure
RUN_DEPENDS=	runawk:${PORTSDIR}/lang/runawk

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	SUBPRJ_DFLT="${SUBPRJ_DFLT}"

SUBPRJ_DFLT=	${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
SUBPRJ_DFLT+=	doc
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
SUBPRJ_DFLT+=	examples
MAKE_ENV+=	EGDIR="${EXAMPLESDIR}"
.endif

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}_reorder

MAN1=		${PORTNAME}.1 \
		${PORTNAME}_reorder.1

do-build:
	@${SETENV} ${MAKE_ENV} LDFLAGS="${LDFLAGS}" ${LOCALBASE}/bin/mkcmake -C ${WRKSRC}

do-install:
	@${SETENV} ${MAKE_ENV} LDFLAGS="${LDFLAGS}" ${LOCALBASE}/bin/mkcmake -C ${WRKSRC} ${INSTALL_TARGET}

.include <bsd.port.mk>
