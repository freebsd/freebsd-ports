# New ports collection makefile for:	hnb
# Date created:				Fri Jul  6 05:37:14 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	hnb
PORTVERSION=	1.9.17
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Hierarchical NoteBook a data organizer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=

MAN1=		hnb.1

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/libcli/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hnb ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/../doc/hnb.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in Documentation.hnb Documentation.html hnbrc
	${INSTALL_DATA} ${WRKSRC}/../doc/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
