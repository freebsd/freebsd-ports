# New ports collection makefile for:	ja-tcsh NLS catalog (Generic Japanese)
# Version required:	6.07.12
# Date created:		19 August 1998
# Whom:			issei <issei@jp.FreeBSD.ORG>
#
# $Id$
#

.if !defined(NLSSRC)
DISTNAME=	tcsh-6.07.12
PKGNAME=	ja-tcsh-nls-generic-6.07.12
CATEGORIES=	japanese shells
MASTER_SITES=	ftp://ftp.astron.com/pri/

MAINTAINER=	issei@jp.FreeBSD.ORG

PATCH_DIST_STRIP=	-p1
NLSSRC=		${DISTNAME}/nls/ja
.endif

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	tcsh:${PORTSDIR}/japanese/tcsh

NLSDIR=		${PREFIX}/share/nls
GENCAT=		/usr/bin/gencat
NKF=		${PREFIX}/bin/nkf
NLSSRC_FULL=	${WRKDIR}/${NLSSRC}

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
	${INSTALL_DATA} ${NLSSRC_FULL}/tcsh.cat ${NLSDIR}/ja_JP.EUC/tcsh.cat; \
	${INSTALL_DATA} ${NLSSRC_FULL}/tcsh.m ${NLSDIR}/ja_JP.EUC/tcsh.m; \
	${INSTALL_DATA} ${NLSSRC_FULL}_sjis/tcsh.cat ${NLSDIR}/ja_JP.SJIS/tcsh.cat; \
	${INSTALL_DATA} ${NLSSRC_FULL}_sjis/tcsh.m ${NLSDIR}/ja_JP.SJIS/tcsh.m; \

.include <bsd.port.mk>
