# New ports collection makefile for:	today
# Date created:		24 June 1996
# Whom:			ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	today
PORTVERSION=	2.11a
CATEGORIES=	japanese games
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/dos/personal/calendar/today/
DISTNAME=	ja-${PORTNAME}-${PORTVERSION}
DISTFILES=	td${PORTVERSION:S/.//}s.lzh \
		td${PORTVERSION:S/.//}m.lzh

MAINTAINER=	rewsirow@ff.iij4u.or.jp
COMMENT=	Tells you what day today is

EXTRACT_DEPENDS=lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xfqw=${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty

NO_WRKSUBDIR=	yes

post-extract:
	@${ECHO_MSG} "===>  Extracting tbl file for ${DISTNAME}"
	@(cd ${WRKSRC}; lha xqf tbl.lzh )
	@${ECHO_MSG} "===>  Converting Kanji code for ${DISTNAME}"
	@(cd ${WRKSRC}; \
	for i in *.c *.h *.doc *.cnf birthday.tbl event*.tbl flower.tbl \
		 gengo.tbl hist??.tbl history.tbl holiday.tbl magazine.tbl \
		 monthly.tbl schedule.tbl suffix.tbl week.tbl; \
	do \
		${SED} 's/.$$//' $$i | nkf -Se > $$i.tmp ;\
		${MV} -f $$i.tmp $$i ; \
	done)
	@(cd ${WRKSRC}; lha xiqf utility.lzh src/dayinfo.c )

pre-patch:
	@${ECHO_MSG} "===>  Installing custom Makefile for ${DISTNAME}"
	@(${CP} ${FILESDIR}/Makefile ${WRKSRC})

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/*.cnf

.include <bsd.port.mk>
