# New ports collection makefile for:	teapot
# Date created:				7 January 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	teapot
PORTVERSION=	2.2.0
CATEGORIES=	deskutils
MASTER_SITES=	http://www.syntax-k.de/projekte/${PORTNAME}/ \
		http://www.syntax-k.de/projekte/${PORTNAME}/:docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${DISTNAME:C/^./T/}-Linux-x86${EXTRACT_SUFX}:docs

MAINTAINER=	corky1951@comcast.net
COMMENT=	Full-screen curses based spread sheet program

USE_CMAKE=	yes

# We download the prebuilt binary tarball for Linux in order to avoid
# having to generate the pdf and html docs from the LyX sourcecode.
WRKSRC_DOCS=	${WRKDIR}/${DISTNAME:C/^./T/}-Linux/share/doc/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC_DOCS} && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
