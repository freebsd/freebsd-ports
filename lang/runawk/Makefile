# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	runawk
PORTVERSION=	1.5.1
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for AWK interpreter that implements a modules system

LICENSE=	MIT

BUILD_DEPENDS=	mk-configure>=0.26.0:${PORTSDIR}/devel/mk-configure

MAKE_ENV=	DESTDIR="${STAGEDIR}" EGDIR="${EXAMPLESDIR}" \
		SUBPRJ_DFLT="${SUBPRJ_DFLT}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS EXAMPLES

SUBPRJ_DFLT=	runawk modules doc examples

do-build:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC}

do-install:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC} \
		${INSTALL_TARGET}

.include <bsd.port.mk>
