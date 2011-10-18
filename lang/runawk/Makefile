# New ports collection makefile for:	runawk
# Date created:				28 March 2010
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	runawk
PORTVERSION=	1.3.2
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Wrapper for AWK interpreter that implements a modules system

BUILD_DEPENDS=	mk-configure>=0.21.0:${PORTSDIR}/devel/mk-configure

MAKE_ENV+=	SUBPRJ_DFLT="${SUBPRJ_DFLT}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,-rpath -Wl,${LOCALBASE}/lib

MAN1=		${PORTNAME}.1 alt_getopt.1

PLIST_FILES=	bin/${PORTNAME} bin/alt_getopt bin/alt_getopt.sh

SUBPRJ_DFLT=	runawk modules

LICENSE=	MIT

.if !defined(NOPORTDOCS)
PORTDOCS=	*
SUBPRJ_DFLT+=	doc
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
SUBPRJ_DFLT+=	examples
MAKE_ENV+=	EGDIR="${EXAMPLESDIR}"
.endif

do-build:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC}

do-install:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC} ${INSTALL_TARGET}

post-install:
	@(cd ${DATADIR}; ${FIND} -s . -type f) \
		| ${SED} -ne 's,^,${DATADIR:S,^${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}/gawk' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}' >> ${TMPPLIST}

.include <bsd.port.mk>
