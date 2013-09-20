# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	robodoc
PORTVERSION=	4.99.41
CATEGORIES=	devel
MASTER_SITES=	http://rfsber.home.xs4all.nl/Robo/ \
		http://seis.bris.ac.uk/~mexas/distfiles/

MAINTAINER=	mexas@bris.ac.uk
COMMENT=	Code reference program similar to cxref that produces HTML

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		robodoc.1 robohdrs.1

OPTIONS_DEFINE= DOCS EXAMPLES

DOCS_FILES=	AUTHORS ChangeLog NEWS README Docs/manual.html Docs/manual.css \
		Docs/robodoc_example.rc
PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	bin/robodoc bin/robohdrs

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Source/robodoc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Source/robohdrs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Docs/robodoc.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Docs/robohdrs.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS_FILES:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/Examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
