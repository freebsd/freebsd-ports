# New ports collection Makefile for:	taskwarrior
# Date created:				12 June 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	taskwarrior
PORTVERSION=	1.7.1
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/
DISTNAME=	task-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A framework for supercharged task and contact management

WRKSRC=		${WRKDIR}/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}

GNU_CONFIGURE=	yes

MAN1=	task.1
MAN5=	taskrc.5

.if defined(NOPORTDOCS)
post-patch:
	${REINPLACE_CMD} -e '/^other_DATA/d' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
