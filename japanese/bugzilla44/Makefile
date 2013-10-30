# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	4.4.1
CATEGORIES=	japanese
MASTER_SITES=	http://bug-ja.org/releases/4.4/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/bugzilla-ja
DISTNAME=	Bugzilla-ja-${PORTVERSION}-template

MAINTAINER=	bugzilla@FreeBSD.org
COMMENT=	Japanese localization for Bugzilla

RUN_DEPENDS=	bugzilla44>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla44

NO_WRKSUBDIR=	yes

.include "${.CURDIR}/../../devel/bugzilla44/Makefile.common"

USE_BZIP2=	yes

LANGDIR=	${WWWDIR}/template/ja

do-install:
	@-${MKDIR} ${STAGEDIR}${LANGDIR}/default
	@cd ${WRKDIR}/default; ${COPYTREE_SHARE} . ${STAGEDIR}${LANGDIR}/default

# Maintainer
plist: patch
	@( cd ${WRKDIR}/ && ${FIND} default -type f | ${AWK} '{print "%%WWWDIR%%/template/ja/"$$1}' | ${SORT} > ${PLIST}.new )
	@( cd ${WRKDIR}/ && ${FIND} default -type d | ${AWK} '{print "@dirrmtry %%WWWDIR%%/template/ja/"$$1}' | ${SORT} -r >> ${PLIST}.new )
	@${ECHO} "@dirrmtry %%WWWDIR%%/template/ja" >> ${PLIST}.new
	@if ${DIFF} -u ${PLIST} ${PLIST}.new ; then \
		${ECHO_MSG} no pkg-plist changes; \
		${RM} ${PLIST}.new ; \
	fi

.include <bsd.port.mk>
