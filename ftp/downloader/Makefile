# New ports collection makefile for:	downloader
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	downloader
PORTVERSION=	1.19
CATEGORIES=	ftp
MASTER_SITES=	http://www.krasu.ru/soft/chuchelo/files/ \
		ftp://ftp.server51.freshmeat.net/pub/d4x/ \
		ftp://ftp.chg.ru/pub/X11/applications/Xdownloader/
DISTNAME=	nt-${PORTVERSION}

MAINTAINER=	andrew@chg.ru

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

MSGFMT_CMD=	${LOCALBASE}/bin/msgfmt

WRKSRC=		${WRKDIR}/${DISTNAME}/main

USE_GTK=	yes
MAKE_ENV=	MSGFMT_CMD="${MSGFMT_CMD}"

MAN1=		nt.1

D4X_DOC=	ChangeLog FAQ FAQ.de FAQ.es FAQ.fr FAQ.gr LICENSE     \
		NAMES PLANS README README.de README.es README.gr      \
		README.pl README.pt_BR README.ru THANKS TODO TROUBLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/../nt.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/downloader
.for file in ${D4X_DOC}
	${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/downloader
.endfor
.endif

.include <bsd.port.mk>
