# New ports collection makefile for:	downloader
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	downloader
PORTVERSION=	1.15
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.server51.freshmeat.net/pub/d4x/ \
		ftp://ftp.chg.ru/pub/X11/applications/Xdownloader/
DISTNAME=	nt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
MSGFMT_CMD=	${LOCALBASE}/bin/msgfmt

WRKSRC=		${WRKDIR}/${DISTNAME}/main

MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		MSGFMT_CMD="${MSGFMT_CMD}"

MAN1=		nt.1

D4X_DOC=	ChangeLog FAQ FAQ.es FAQ.fr FAQ.gr INSTALL INSTALL.gr LICENSE \
		NAMES PLANS README README.gr README.ru THANKS TODO TROUBLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/../nt.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/downloader
.for file in ${D4X_DOC}
	${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/downloader
.endfor
.endif

.include <bsd.port.mk>
