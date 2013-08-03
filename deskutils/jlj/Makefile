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

SHEBANG_FILES=	jlj.pl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jlj.pl ${PREFIX}/bin/jlj
	@${MKDIR} ${PREFIX}/share/examples/jlj
	${INSTALL_DATA} ${WRKSRC}/.livejournal.rc \
		${PREFIX}/share/examples/jlj/dot.livejournal.rc
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.JLJ ${DOCSDIR}/README
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
