# ex:ts=8
#
# New ports collection makefile for:	knowit
# Date created:			2002/12/08
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	knowit
PORTVERSION=	0.8
PORTREVISION=	0
#PORTEPOCH=
CATEGORIES=	deskutils
MASTER_SITES=	http://knowit.sourceforge.net/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A note manager with tree organization that uses RTF for storage

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

BINDIR=		${PREFIX}/bin
BINNAME=	${CONFIGURE_TARGET}-${PORTNAME}
PLIST_SUB=	BINNAME=${BINNAME}

post-install:
	cd ${BINDIR}; ${RM} -f ${PORTNAME}; \
		${LN} -sf ${BINNAME} ${PORTNAME}

.include <bsd.port.mk>
#EOF
