# New ports collection Makefile for:	taskwarrior
# Date created:				12 June 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	taskwarrior
DISTVERSION=	2.1.1
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/
DISTNAME=	task-${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A framework for supercharged task and contact management

OPTIONS_DEFINE=	LUA

WRKSRC=		${WRKDIR}/task-${DISTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1
.endif

USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
CMAKE_ARGS+=	-DTASK_DOCDIR:STRING=${DATADIR:S/${PREFIX}\///} \
   		-DTASK_MAN1DIR:STRING=man/man1 \
		-DTASK_MAN5DIR:STRING=man/man5

MAN1=		task.1
MAN5=		taskrc.5 task-faq.5 task-color.5 task-sync.5 task-tutorial.5

.include <bsd.port.mk>
