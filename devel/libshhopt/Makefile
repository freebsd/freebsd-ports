# ex:ts=8
# New ports collection makefile for:	libshhopt
# Date created:				11 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	libshhopt
PORTVERSION=	1.1.7
CATEGORIES=	devel
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/
DISTNAME=	shhopt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for parsing command line options

MAKEFILE=	${FILESDIR}/Makefile.lib
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/Makefile ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.c ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
