# New ports collection makefile for:	runawk
# Date created:				28 March 2010
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	runawk
PORTVERSION=	1.1.0
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Wrapper for AWK interpreter that implements a modules system

MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -Wl,-rpath -Wl,${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	ChangeLog NEWS README TODO
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/*.awk \
		${WRKSRC}/modules/gawk/* ${DATADIR}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${MANPREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 555 -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
	@(cd ${DATADIR}; ${FIND} -s *) \
		| ${SED} -ne 's,^,${DATADIR:S,^${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S|${PREFIX}/||}' >> ${TMPPLIST}

.include <bsd.port.post.mk>
