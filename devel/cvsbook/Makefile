# New ports collection makefile for:	cvsbook
# Date created:		2002/02/28
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cvsbook
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cvsbook.red-bean.com/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tutorial and reference for CVS

BROKEN=		"Size mismatch"

ALL_TARGET=	version
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INFO=		cvsbook
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.html \
		%%DOCSDIR%%/cvsbook.pdf \
		%%DOCSDIR%%/cvsbook.ps

.if defined(WITH_SPLIT_HTML)
ALL_TARGET+=	html-monolithic
.endif

.if !defined(WITH_SPLIT_HTML)
pre-everything::
	@${ECHO_MSG} "You can install SPLIT-HTML format of cvsbook"
	@${ECHO_MSG} "by defining WITH_SPLIT_HTML"
.endif

do-install:
	@${MKDIR} ${DOCSDIR}/cvsbook-shtml
.if defined(WITH_SPLIT_HTML)
	@cd ${WRKSRC}/cvsbook && ${FIND} . -type f| ${CUT} -c2- \
	| ${SED} 's|^|${DOCSDIR:S,${PREFIX}/,,}/cvsbook-shtml/|' \
	| ${SORT} >> ${TMPPLIST}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook/* ${DOCSDIR}/cvsbook-shtml/
.endif
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.info* ${PREFIX}/info
	@install-info ${PREFIX}/info/cvsbook.info ${PREFIX}/info/dir
	@${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}/cvsbook-shtml" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}

.include <bsd.port.mk>
