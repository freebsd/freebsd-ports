# New ports collection Makefile for:	taskwarrior
# Date created:				12 June 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	taskwarrior
PORTVERSION=	1.8.5
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/
DISTNAME=	task-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A framework for supercharged task and contact management

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes

MAN1=	task.1
MAN5=	taskrc.5 task-tutorial.5

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|; s|%%DATADIR%%|${DATADIR}|' \
	    ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '342,349d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
