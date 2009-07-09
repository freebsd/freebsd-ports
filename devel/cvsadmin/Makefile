# ex:ts=8
# Ports collection makefile for:	cvsadmin
# Date Created:			Jun 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsadmin
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	LOCAL/gabor

MAINTAINER=	aehlig@linta.de
COMMENT=	A simple program to administrate users of a CVS repository

GNU_CONFIGURE=	yes

MAN1=		cvsadmin.1
PLIST_FILES=	bin/cvsadmin

post-configure:
	${ECHO_CMD} "#define HAVE_MKDTEMP 1" >> ${WRKSRC}/config.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/cvsadmin.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
