# New ports collection makefile for: X Japanese man documents
# Date created:		24 Dec 1998
# Based on:		Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>'s
#			japanese/man-doc
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xjman
PORTVERSION?=	0.7
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES?=	${MASTER_SITE_PORTS_JP} \
		http://xjman.dsl.gr.jp/dist/

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Japanized X manual from "The X Japanese Documentation Project"

RUN_DEPENDS=	jman:${PORTSDIR}/japanese/man

USE_REINPLACE=	yes
USE_PERL5=	yes
NO_MTREE=	yes
PLIST=		${WRKDIR}/PLIST
USE_BZIP2=	yes
WRKSRC?=	${WRKDIR}/xjman
SCRIPTS_ENV+=	MANSECS="${MANSECS}"

MANSECS=	1 3 5

.include <bsd.port.pre.mk>

post-extract:
.for i in Makefile Makefile.inc
	@${CP} ${FILESDIR}/$i ${WRKSRC}
.endfor
.for sec in ${MANSECS}
	(cd ${WRKSRC}/man${sec}; \
	for f in *.${sec}x; do ${CP} $$f $${f%x}; done; \
	${REINPLACE_CMD} -e 's/^\(\.so .*\)x$$/\1/' *.${sec})
.endfor

post-build:
	@${RM} -f ${PLIST}
	@for sec in ${MANSECS}; do \
	if [ -d ${WRKSRC}/man$${sec} ]; then \
		cd ${WRKSRC}/man$${sec}; \
		list=`${MAKE} pages-list`; \
		set `${ECHO_CMD} $$list " "|${SED} 's/\.\([0-9]\) /.\1 \1 /g'`; \
		while : ; do \
			case $$# in \
				0) break;; \
				[1]) ${ECHO_CMD} "can not happen"; break;; \
			esac; \
			${ECHO_CMD} man/ja/man$$2/$$1.gz; shift 2; \
		done; \
	fi; \
	done|${SORT}|uniq >>${PLIST}
	@${ECHO_CMD} "@exec ${LN} -sf %D/man/ja %D/man/ja_JP.EUC" >>${PLIST}
	@${ECHO_CMD} "@unexec ${RM} -f %D/man/ja_JP.EUC" >>${PLIST}
	@${ECHO_CMD} "share/doc/xjman/COPYRIGHT" >>${PLIST}
	@${ECHO_CMD} "share/doc/xjman/COPYRIGHT.XJDP" >>${PLIST}
	@${ECHO_CMD} "@dirrm share/doc/xjman" >>${PLIST}

pre-install:
.for sec in ${MANSECS}
	@${MKDIR} ${PREFIX}/man/ja/man${sec}
.endfor

post-install:
	@${MKDIR} ${PREFIX}/share/doc/xjman
.for i in COPYRIGHT COPYRIGHT.XJDP
	@${INSTALL_DATA} ${FILESDIR}/$i ${PREFIX}/share/doc/xjman/
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
