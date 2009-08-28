# New ports collection makefile for:	pipestatus
# Date created:				2008/01/26
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	pipestatus
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UNIX/POSIX shell helper for running pipes safely

NO_BUILD=	yes

PLIST_FILES=	bin/pipestatus
.if !defined(NOPORTDOCS)
PLIST_DIRS=	${DOCSDIR_REL}
PLIST_FILES+=	${DOCSDIR_REL}/README \
		${DOCSDIR_REL}/NEWS
.endif
DOCS=		README NEWS

do-install:
	${INSTALL_DATA} ${WRKSRC}/pipestatus ${DESTDIR}${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
