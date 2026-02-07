PORTNAME=	raidtest
PORTVERSION=	1.3
CATEGORIES=	benchmarks
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pjd@FreeBSD.org
COMMENT=	Test performance of storage devices

LICENSE=	BSD2CLAUSE

NO_WRKSUBDIR=	yes
USES=		uidfix
PLIST_FILES=	bin/raidtest
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-extract:
	@${MKDIR} ${WRKSRC}
	${LN} -sf ${FILESDIR}/${PORTNAME}.c ${FILESDIR}/Makefile ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
