# New ports collection makefile for:	cgdb
# Date created:		2005-12-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cgdb
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	A curses-based interface to the GNU Debugger

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/cgdb

post-patch:
	${REINPLACE_CMD} -e 's,libutil\.h,,g' ${WRKSRC}/configure

.include <bsd.port.mk>
