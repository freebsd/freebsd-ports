# New ports collection makefile for:	Japanese man documents
# Date created:		6 January 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	man-doc
PORTVERSION=	4.5
CATEGORIES=	japanese
DISTFILES=	# none

MAINTAINER=	horikawa@jp.FreeBSD.org

PREFIX?=	/usr
NO_CHECKSUM=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/man
PLIST=		${WRKDIR}/PLIST

MANSECS=	1 2 5 6 7 8 9
JAMANDIR?=	/usr/opt/doc/ja_JP.eucJP/man

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
		${ECHO} >>${WRKSRC}/man${sec}/Makefile; \
		${ECHO} pages-list: >>${WRKSRC}/man${sec}/Makefile; \
		${ECHO} "	@\$${ECHO} \$${MAN${sec}} \$${MLINKS}" \
			>>${WRKSRC}/man${sec}/Makefile; \
	fi
.endfor

post-build:
	@${RM} -f ${PLIST}
	@for sec in ${MANSECS}; do \
	 if [ -d ${WRKSRC}/man$${sec} ]; then \
		cd ${WRKSRC}/man$${sec}; \
		list=`${MAKE} pages-list`; \
		set `${ECHO} $$list " "|${SED} 's/\.\([^.]*\) /.\1 \1 /g'`; \
		while : ; do \
			case $$# in \
				0) break;; \
				[1]) ${ECHO} "can not happen"; break;; \
			esac; \
			${ECHO} share/man/ja/man$$2/$$1.gz; shift 2; \
		done; \
	 fi; \
	done|sort|uniq >>${PLIST}

pre-install:
.for sec in ${MANSECS}
	@${MKDIR} ${PREFIX}/share/man/ja/man${sec}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
