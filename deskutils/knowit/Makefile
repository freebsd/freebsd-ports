# ex:ts=8
#
# New ports collection makefile for:	knowit
# Date created:			2002/12/08
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	knowit
PORTVERSION=	0.4
PORTREVISION=	0
#PORTEPOCH=
CATEGORIES=	deskutils
MASTER_SITES=	http://www.uw.edu.pl/~mrudolf/files/

MAINTAINER=	alane@FreeBSD.org

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

BINDIR=		${PREFIX}/bin

post-install:
	cd ${BINDIR}; rm -f ${PORTNAME}; \
		ln -sf ${CONFIGURE_TARGET}-${PORTNAME} ${PORTNAME}

.include <bsd.port.mk>
#EOF
