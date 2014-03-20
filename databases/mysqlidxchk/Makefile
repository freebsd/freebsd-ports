# Created by: Andrey Ignatov <rdna@rdna.ru>
# $FreeBSD$

PORTNAME=	mysqlidxchk
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/scripts/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rdna@rdna.ru
COMMENT=	Checks MySQL databases/tables for unused indexes

RUN_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

NO_WRKSUBDIR=	yes

USES=		perl5 shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/mysqlidxchk
SHEBANG_FILES=	mysqlidxchk
PORTDOCS=	mysqlidxchkdoc.html mysqlidxchkguide.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mysqlidxchk ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
