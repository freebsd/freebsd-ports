PORTNAME=	jlj
PORTVERSION=	2.12
CATEGORIES=	deskutils net
MASTER_SITES=	http://umlautllama.com/projects/perl/ \
		http://www.atarininja.org/~wxs/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jerry's command-line LiveJournal.com entry system

USES=		shebangfix perl5
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/jlj
PORTDOCS=	README
PORTEXAMPLES=	dot.livejournal.rc

SHEBANG_FILES=	jlj.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jlj.pl ${STAGEDIR}${PREFIX}/bin/jlj

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.livejournal.rc \
		${STAGEDIR}${EXAMPLESDIR}/dot.livejournal.rc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.JLJ ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
