# ex:ts=8
# New ports collection makefile for:	elfio
# Date created:			Jul 26, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	elfio
PORTVERSION=	0.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	ELF (Executable and Linkable Format) reader and producer

WRKSRC=		${WRKDIR}/ELFIO/ELFIO
MAKEFILE=	makefile
USE_REINPLACE=	yes
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s,^CXXFLAGS,#CXXFLAGS,g" ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libELFIO.a ${PREFIX}/lib

.include <bsd.port.mk>
