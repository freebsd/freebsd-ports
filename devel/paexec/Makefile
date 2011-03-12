# New ports collection makefile for:	paexec
# Date created:				2008/01/26
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	paexec
PORTVERSION=	0.16
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Parallel executor, distributes tasks over network

LIB_DEPENDS=	maa:${PORTSDIR}/devel/libmaa
BUILD_DEPENDS=	mk-configure>=0.20:${PORTSDIR}/devel/mk-configure
RUN_DEPENDS=	runawk:${PORTSDIR}/lang/runawk

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		NEWS README TODO
MAN1=		paexec.1 paexec_reorder.1

USE_PERL5_BUILD=	yes

LICENSE=	MIT

do-build:
	@${SETENV} ${MAKE_ENV} LDFLAGS="${LDFLAGS}" ${LOCALBASE}/bin/mkcmake -C ${WRKSRC}

do-install:
	@${SETENV} ${MAKE_ENV} LDFLAGS="${LDFLAGS}" ${LOCALBASE}/bin/mkcmake -C ${WRKSRC} install
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
