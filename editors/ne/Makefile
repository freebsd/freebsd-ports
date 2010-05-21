# New ports collection makefile for:	ne
# Date created:		2005-07-21
# Whom:			Andrej Zverev <az@inec.ru>
#
# $FreeBSD$
#

PORTNAME=	ne
PORTVERSION=	2.1
CATEGORIES=	editors
MASTER_SITES=	http://ne.dsi.unimi.it/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice and powerfull editor

BUILD_WRKSRC=	${WRKSRC}/src

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="-lgnuregex" \
		NE_GLOBAL_DIR="${DATADIR}"
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1
INFO=		${PORTNAME}
PORTDOCS=	${PORTNAME}.txt
PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/default.keys \
		%%DATADIR%%/default.menus
PLIST_DIRS=	%%DATADIR%%

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNODEBUG
.endif

post-patch:
.for file in actions.c
	@${REINPLACE_CMD} -e 's|tmpnam(|mkstemp(|g' ${BUILD_WRKSRC}/${file}
.endfor
.for file in ne.c search.c
	@${REINPLACE_CMD} -e 's|"regex\.h"|<gnu/regex.h>|g' ${BUILD_WRKSRC}/${file}
.endfor
.for file in makefile
	@${REINPLACE_CMD} -e '/[[:space:]]regex.o/d ; \
		 s|regex.h||g' ${BUILD_WRKSRC}/${file}
.endfor

post-build:
	cd ${WRKSRC}/doc && makeinfo ${PORTNAME}.texinfo

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info ${PREFIX}/${INFO_PATH}
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}	${WRKSRC}/doc/default.keys ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/default.menus ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
