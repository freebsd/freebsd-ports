# Created by: ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
# $FreeBSD$

PORTNAME=	today
PORTVERSION=	2.12
CATEGORIES=	japanese games
MASTER_SITES=	http://ftp.vector.co.jp/pack/dos/personal/calendar/today/
DISTNAME=	ja-${PORTNAME}-${PORTVERSION}
DISTFILES=	td${PORTVERSION:S/.//}s.lzh \
		td${PORTVERSION:S/.//}m.lzh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tells you what day today is

EXTRACT_DEPENDS=nkf:${PORTSDIR}/japanese/nkf

NO_WRKSUBDIR=	yes
USES=		lha

MAKEFILE=	${FILESDIR}/Makefile

NO_STAGE=	yes
post-extract:
	@(cd ${WRKSRC}; lha xiqf utility.lzh src/dayinfo.c )
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

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/*.cnf

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/today.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
