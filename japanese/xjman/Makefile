# New ports collection makefile for: X Japanese man documents
# Version required:	0.2
# Date created:		24 Dec 1998
# Based on:		Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>'s
#			japanese/man-doc
# Whom:			SADA Kenji <sada@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	xjman-0.2
CATEGORIES=	japanese
MASTER_SITES=	http://WWW.jp.FreeBSD.ORG/~sada/distfiles/ \
		http://www.dsl.gr.jp/~go/xjman/ \
		http://WWW.FreeBSD.ORG/~sada/distfiles/

MAINTAINER=	sada@FreeBSD.ORG

NO_MTREE=	yes
PLIST=		${WRKDIR}/PLIST
WRKSRC=		${WRKDIR}/man/ja_JP.ujis

MANSECS=	1 3 5

post-extract:
.for i in Makefile Makefile.inc
	@${CP} ${FILESDIR}/$i ${WRKSRC}
.endfor
.for i in ${MANSECS}
	@cd ${WRKSRC}/man$i; \
	ls *.$ix|awk 'BEGIN{printf"MAN$i ="}{printf"\\\n\t%s",$$0}' >Makefile; \
	${ECHO} >>Makefile; \
	${ECHO} pages-list: >>${WRKSRC}/man$i/Makefile; \
	${ECHO} "	@\$${ECHO} \$${MAN$i}" >>${WRKSRC}/man$i/Makefile; \
	${ECHO} >>Makefile; \
	${ECHO} '.include "bsd.prog.mk"' >>Makefile
.endfor

post-build:
	@${RM} -f ${PLIST}
	@for sec in ${MANSECS}; do \
	if [ -d ${WRKSRC}/man$${sec} ]; then \
		cd ${WRKSRC}/man$${sec}; \
		list=`${MAKE} pages-list`; \
		set `${ECHO} $$list " "|${SED} 's/\.\([0-9]\)x /.\1x \1 /g'`; \
		while : ; do \
			case $$# in \
				0) break;; \
				[1]) ${ECHO} "can not happen"; break;; \
			esac; \
			${ECHO} man/ja/man$$2/$$1.gz; shift 2; \
		done; \
	fi; \
	done|sort|uniq >>${PLIST}
	@${ECHO} "@exec ln -sf %D/man/ja %D/man/ja_JP.EUC" >>${PLIST}
	@${ECHO} "@unexec ${RM} -f %D/man/ja_JP.EUC" >>${PLIST}
	@${ECHO} "share/doc/xjman/COPYRIGHT" >>${PLIST}
	@${ECHO} "share/doc/xjman/COPYRIGHT.XJDP" >>${PLIST}
	@${ECHO} "@dirrm share/doc/xjman" >>${PLIST}

pre-install:
.for sec in ${MANSECS}
	@${MKDIR} ${PREFIX}/man/ja/man${sec}
.endfor

post-install:
	@${MKDIR} ${PREFIX}/share/doc/xjman
.for i in COPYRIGHT COPYRIGHT.XJDP
	@${INSTALL_DATA} ${FILESDIR}/$i ${PREFIX}/share/doc/xjman/
.endfor
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
