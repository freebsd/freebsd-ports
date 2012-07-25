# New ports collection makefile for:	ja-bugzilla
# Date created:		2004-01-19
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
PORTVERSION=	4.2.1
CATEGORIES=	japanese
MASTER_SITES=	http://bug-ja.org/releases/4.2/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/bugzilla-ja
PKGNAMESUFFIX=	-ja
DISTNAME=	Bugzilla-ja-${PORTVERSION}-template-rel01

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Japanese localization for Bugzilla

RUN_DEPENDS=	bugzilla>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla42

LATEST_LINK=	${PKGNAMEPREFIX}bugzilla42${PKGNAMESUFFIX}

.include "${.CURDIR}/../../devel/bugzilla42/Makefile.common"

USE_BZIP2=	yes

LANGDIR=	${WWWDIR}/template/ja

do-install:
	@-${MKDIR} ${LANGDIR}/default
	@cd ${WRKDIR}/default; ${COPYTREE_SHARE} . ${LANGDIR}/default
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

x-generate-plist:
	${FIND} ${LANGDIR} -type f | ${SORT} | ${SED} -e 's,${WWWDIR},%%WWWDIR%%,' > pkg-plist.new
	${FIND} ${LANGDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${WWWDIR},@dirrmtry %%WWWDIR%%,' >> pkg-plist.new
	${ECHO} "@dirrmtry %%WWWDIR%%/template" >> pkg-plist.new
	${ECHO} "@dirrmtry %%WWWDIR%%" >> pkg-plist.new

.include <bsd.port.mk>
