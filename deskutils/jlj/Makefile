# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	jlj
PORTVERSION=	2.12
CATEGORIES=	deskutils net
MASTER_SITES=	http://umlautllama.com/projects/perl/ \
		http://www.atarininja.org/~wxs/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jerry's command-line LiveJournal.com entry system

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		shebangfix perl5
USE_PERL5=	run
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	bin/jlj share/examples/jlj/dot.livejournal.rc
PLIST_DIRS=	share/examples/jlj
PORTDOCS=	README

SHEBANG_FILES=	jlj.pl

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jlj.pl ${STAGEDIR}${PREFIX}/bin/jlj
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/jlj
	${INSTALL_DATA} ${WRKSRC}/.livejournal.rc \
		${STAGEDIR}${PREFIX}/share/examples/jlj/dot.livejournal.rc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.JLJ ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
