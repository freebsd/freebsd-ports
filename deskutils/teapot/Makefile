# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	teapot
PORTVERSION=	2.3.0
CATEGORIES=	deskutils
MASTER_SITES=	http://www.syntax-k.de/projekte/${PORTNAME}/ \
		http://www.syntax-k.de/projekte/${PORTNAME}/:docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${DISTNAME:C/^./T/}-Linux-i386${EXTRACT_SUFX}:docs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-screen curses based spread sheet program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake ncurses

# We download the prebuilt binary tarball for Linux in order to avoid
# having to generate the pdf and html docs from the LyX sourcecode.
WRKSRC_DOCS=	${WRKDIR}/${DISTNAME:C/^./T/}-Linux/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC_DOCS} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
