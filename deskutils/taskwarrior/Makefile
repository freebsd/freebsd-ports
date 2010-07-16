# New ports collection Makefile for:	taskwarrior
# Date created:				12 June 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	taskwarrior
PORTVERSION=	1.9.2
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/
DISTNAME=	task-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A framework for supercharged task and contact management

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes

MAN1=	task.1
MAN5=	taskrc.5 task-faq.5 task-color.5 task-tutorial.5

CONFIGURE_ARGS+=--datadir=${DATADIR} --docdir=${DOCSDIR}

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

.include <bsd.port.pre.mk>

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '396,406d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
