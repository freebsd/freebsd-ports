# New ports collection makefile for:	Japanese man documents
# Version required:	2.2
# Date created:		6 January 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.18 1998/03/20 16:30:27 itojun Exp $
#

DISTNAME=	jpman-2.2
PKGNAME=	ja-man-doc-2.2
CATEGORIES=	japanese
DISTFILES=	# none

MAINTAINER=	horikawa@jp.FreeBSD.org

PREFIX?=	/usr
NO_CHECKSUM=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/man

LANGNAME=	ja
MANSECS=	1 5 8
JAMANDIR?=	/usr/opt/doc/ja/man

do-extract:
	@if [ ! -d ${JAMANDIR} ]; then \
	  ${ECHO} "You need the Japanese manual source in"; \
	  ${ECHO} "\"${JAMANDIR}\""; \
	  ${ECHO} "in order to build this port."; \
	  exit 1; \
	fi
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@(cd ${JAMANDIR}; ${CP} Makefile Makefile.inc  ${WRKSRC})
.for sec in ${MANSECS}
	@if [ -d ${JAMANDIR}/man${sec} ]; then \
		${CP} -R ${JAMANDIR}/man${sec} ${WRKSRC}/ ; \
	fi
.endfor

pre-install:
.for sec in ${MANSECS}
	@${MKDIR} ${PREFIX}/share/man/ja/man${sec}
.endfor

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
