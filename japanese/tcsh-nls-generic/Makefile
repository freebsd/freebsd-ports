# New ports collection makefile for:	ja-tcsh NLS catalog (Generic Japanese)
# Date created:		19 August 1998
# Whom:			Issei Suzuki <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcsh-nls
PORTVERSION=	6.08.05
PKGNAMESUFFIX=	-${CATALOGNAME}
CATEGORIES=	japanese shells
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
DISTNAME=	tcsh-${PORTVERSION}.add2

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Japanese NLS catalog for TCSH. ("Generic Japanese" taste)

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500006 || ${OSVERSION} < 500000 && ${OSVERSION} >= 400021
FORBIDDEN=	tcsh in base system cannot deal with local message catalogs yet
.endif

CATALOGNAME?=	generic

.if ${CATALOGNAME} == generic
MASTER_SITES+=	ftp://ftp.astron.com/pub/tcsh/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		tcsh-${PORTVERSION}${EXTRACT_SUFX}

NLSSRC=		tcsh-${PORTVERSION}/nls/ja
.else
NLSSRC=		${DISTNAME}/nls/ja.${CATALOGNAME}
.endif

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

.include <bsd.port.post.mk>
