# ex:ts=8
# New ports collection makefile for:	downloader
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	downloader
PORTVERSION=	1.27
CATEGORIES=	ftp
MASTER_SITES=	http://www.krasu.ru/soft/chuchelo/files/ \
		ftp://ftp.server51.freshmeat.net/pub/d4x/ \
		ftp://ftp.chg.ru/pub/X11/applications/Xdownloader/
DISTNAME=	nt-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/main

USE_GTK=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" DEST="${PREFIX}" \
		OSTYPE="${OPSYS}" MAKE_CMD="${GMAKE}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
MAN1=		nt.1

PORTDOCS=	ChangeLog LICENSE NAMES PLANS THANKS TODO TROUBLES \
		FAQ FAQ.de FAQ.es FAQ.fr FAQ.gr \
		INSTALL INSTALL.de INSTALL.es INSTALL.fr INSTALL.gr \
		INSTALL.he INSTALL.pl INSTALL.pt_BR \
		README README.de README.en README.es README.gr \
		README.pl README.pt_BR README.ru

post-install:
	@${INSTALL_MAN} ${WRKSRC}/../nt.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/../${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
