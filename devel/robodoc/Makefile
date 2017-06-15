# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	robodoc
PORTVERSION=	4.99.43
CATEGORIES=	devel
MASTER_SITES=	http://rfsber.home.xs4all.nl/Robo/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Code reference program similar to cxref that produces HTML

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

DOCS_FILES=	AUTHORS ChangeLog NEWS README \
		Docs/manual.html Docs/manual.css Docs/robodoc_example.rc

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Source/robodoc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Source/robohdrs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Docs/robodoc.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Docs/robohdrs.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/Examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
