# New ports collection makefile for:	ja-tcsh NLS catalog (Generic Japanese)
# Version required:	6.08.02
# Date created:		19 August 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/10/10 03:57:29 steve Exp $
#

.if !defined(NLSSRC)
DISTNAME=	tcsh-6.08.02
PKGNAME=	ja-tcsh-nls-generic-6.08.02
CATEGORIES=	japanese shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/ \
		http://www2.wbs.ne.jp/~znc/tcsh/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}.add2${EXTRACT_SUFX}

MAINTAINER=	issei@jp.FreeBSD.ORG

PATCH_DIST_STRIP=	-p1
NLSSRC=		${DISTNAME}/nls/ja
.endif

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	tcsh:${PORTSDIR}/japanese/tcsh

WRKSRC=		${WRKDIR}/tcsh-6.08.02.add2

NLSDIR=		${PREFIX}/share/nls
GENCAT=		/usr/bin/gencat
NKF=		${PREFIX}/bin/nkf
NLSSRC_FULL=	${WRKDIR}/${NLSSRC}
PORTDOCS=	HISTORY.additional HowToMakeNLS.euc README.additional

post-patch:
	@${MKDIR} ${NLSSRC_FULL}_sjis
	@(cd ${NLSSRC_FULL}; \
	for j in set[0-9] set[0-9][0-9] ; do \
	${NKF} -Es $$j | \
	${AWK} '{gsub(/[\x81-\x84\x88-\x9f\xe0-\xea]\\/,"&\\"); print; }' \
	> ${NLSSRC_FULL}_sjis/$$j ; done ; \
	)

do-build:
	@(cd ${NLSSRC_FULL}; \
	${CAT} set[0-9] set[0-9][0-9] > tcsh.m; \
	${GENCAT} tcsh.cat tcsh.m; \
	cd ${NLSSRC_FULL}_sjis; \
	${CAT} set[0-9] set[0-9][0-9] > tcsh.m; \
	${GENCAT} tcsh.cat tcsh.m; \
	)

do-install:
	${INSTALL_DATA} ${NLSSRC_FULL}/tcsh.cat ${NLSDIR}/ja_JP.EUC/tcsh.cat
	${INSTALL_DATA} ${NLSSRC_FULL}/tcsh.m ${NLSDIR}/ja_JP.EUC/tcsh.m
	${INSTALL_DATA} ${NLSSRC_FULL}_sjis/tcsh.cat ${NLSDIR}/ja_JP.SJIS/tcsh.cat
	${INSTALL_DATA} ${NLSSRC_FULL}_sjis/tcsh.m ${NLSDIR}/ja_JP.SJIS/tcsh.m
.if !defined(NOPORTDOCS)
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/tcsh
.endfor
.endif

.include <bsd.port.mk>
