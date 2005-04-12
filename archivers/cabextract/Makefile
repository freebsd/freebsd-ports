# New ports collection makefile for:	cabextract
# Date Created:				30 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cabextract
PORTVERSION=	1.1
CATEGORIES=	archivers
MASTER_SITES=	http://www.kyz.uklinux.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to extract Microsoft cabinet (.CAB) files

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MANLANG=	"" ja
MAN1=		cabextract.1
PORTDOCS=	magic wince_cab_format.html wince_info wince_rename
PLIST_FILES=	bin/cabextract

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ja/cabextract.1 ${MANPREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/magic ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/wince_cab_format.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/wince_info ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/wince_rename ${DOCSDIR}
.endif

.include <bsd.port.mk>
