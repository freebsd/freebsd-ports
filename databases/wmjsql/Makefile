# New ports collection makefile for:	wmjSQL
# Date created:				04 Mar 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmjsql
PORTVERSION=	0.5
CATEGORIES=	databases windowmaker
MASTER_SITES=	http://www.dockapps.org/download.php/id/73/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MySQL server status displaying dockapp

USE_MYSQL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GETOPT_LONG= yes
USE_XPM=	yes

ALL_TARGET=	clean all

WRKSRC=		${WRKDIR}/${PORTNAME}/src

post-patch:
	@${REINPLACE_CMD} -e 's,^INCDIR.*$$,INCDIR = -I${PREFIX}/include/X11 \
		-I${PREFIX}/include -I${LOCALBASE}/include,' \
		-e 's,^LIBDIR.*$$,LIBDIR = -L${PREFIX}/lib \
		-L${LOCALBASE}/lib/mysql,' -e '/^CC/d; /^CFLAGS/d' \
		-e 's,-D$$(shell echo `uname -s`),,' ${WRKSRC}/Makefile \
		${WRKSRC}/jDockApp/Makefile ${WRKSRC}/xutils/Makefile
	@${REINPLACE_CMD} -E 's,\.wmjsql([^r]),\.wmjsqlrc\1,' \
		${WRKSRC}/wmjsql.jet ${WRKSRC}/../README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
