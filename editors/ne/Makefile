# New ports collection makefile for:	ne
# Date created:		2005-07-21
# Whom:			Andrej Zverev <az@inec.ru>
#
# $FreeBSD$
#

PORTNAME=	ne
PORTVERSION=	2.0.3
CATEGORIES=	editors
MASTER_SITES=	http://ne.dsi.unimi.it/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice and powerfull editor

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		NE_GLOBAL_DIR="${DATADIR}"

MAN1=		ne.1
PORTDOCS=	ne.txt
PLIST_FILES=	bin/ne %%DATADIR%%/default.keys %%DATADIR%%/default.menus
PLIST_DIRS=	%%DATADIR%%

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNODEBUG
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|tmpnam(|mkstemp(|g' ${WRKSRC}/actions.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ne ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/ne.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}	${WRKSRC}/../doc/default.keys ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/../doc/default.menus ${DATADIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/ne.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
