# New ports collection makefile for:	runawk
# Date created:				28 March 2010
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	runawk
PORTVERSION=	1.2.0
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Wrapper for AWK interpreter that implements a modules system

BUILD_DEPENDS=	mk-configure>=0.20.0:${PORTSDIR}/devel/mk-configure

MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -Wl,-rpath -Wl,${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		${PORTNAME}.1 alt_getopt.1

PLIST_FILES=	bin/${PORTNAME} bin/alt_getopt bin/alt_getopt.sh

PORTDOCS=	ChangeLog NEWS README TODO
PORTEXAMPLES=	*

LICENSE=	MIT

.include <bsd.port.pre.mk>

do-build:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC}

do-install:
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mkcmake -C ${WRKSRC} ${INSTALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 555 -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
	@(cd ${DATADIR}; ${FIND} -s . -type f) \
		| ${SED} -ne 's,^,${DATADIR:S,^${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}/gawk' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}' >> ${TMPPLIST}

.include <bsd.port.post.mk>
