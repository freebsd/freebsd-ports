# New ports collection makefile for:	devtodo
# Date Created:				26 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	devtodo
PORTVERSION= 	0.1.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.1.6-1

MAINTAINER=	petef@databits.net

WRKSRC=	${WRKDIR}/devtodo-0.1.6

GNU_CONFIGURE=	Yes

MAN1=	devtodo.1
MLINKS=	devtodo.1 tda.1 devtodo.1 tdd.1 devtodo.1 tde.1 devtodo.1 tdr.1 \
	devtodo.1 todo.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/devtodo
.for file in doc/scripts.sh doc/scripts.tcsh doc/todorc.example
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/devtodo
.endfor

.include <bsd.port.mk>
