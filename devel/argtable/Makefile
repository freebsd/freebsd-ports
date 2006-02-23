# ex:ts=8
# Ports collection makefile for:	argtable
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argtable
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/./-/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ANSI C library for parsing GNU style command line arguments

USE_GNOME=	gnometarget
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		argtable2.3
MLINKS=		argtable2.3 argtable.3

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g ; \
		 s|^install-data-am: |install-data-am: #|g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/argtable2.3 ${MAN3PREFIX}/man/man3
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.h ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.txt ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
