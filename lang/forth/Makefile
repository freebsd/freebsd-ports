# New ports collection makefile for:    pfe
# Date created:         23 November 1994
# Whom:                 mr
#
# $FreeBSD$
#

PORTNAME=	pfe
PORTVERSION=	0.9.14
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.taygeta.com/pub/Forth/Compilers/native/unix/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	config.sh
CONFIGURE_ARGS=	${OPSYS}
MAN1=		pfe.1

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/pfe.1 ${PREFIX}/man/man1/pfe.1

.include <bsd.port.mk>
