# New ports collection makefile for:    asl
# Version required:     1.41r6
# Date created:         18 June 1997
# Whom:                 Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1997/06/20 08:13:46 tg Exp $
#

DISTNAME=       asl-1.41r6
CATEGORIES=	devel
MASTER_SITES=	ftp://zam091.zam.kfa-juelich.de/pub/msdos/assembler/c_version/

MAINTAINER=	ports@FreeBSD.org

post-extract:
	${CP} ${FILESDIR}/Makefile.def ${WRKSRC}

post-install:
	${MKDIR} ${PREFIX}/share/doc/asl
	${INSTALL_DATA} ${WRKSRC}/doc_EN/* ${PREFIX}/share/doc/asl

.include <bsd.port.mk>
