# New ports collection makefile for:	de-bugzilla
# Date created:		2011-06-11
# Whom:			Olli Hauer <ohauer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
PORTVERSION=	4.2.2
CATEGORIES=	german
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=bugzilla-de/${PORTVERSION:R}/${PORTVERSION}
DISTNAME=	germzilla-${PORTVERSION}-1.utf-8

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	German localization for Bugzilla

RUN_DEPENDS=	bugzilla>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla42

LATEST_LINK=	${PKGNAMEPREFIX}bugzilla42

NO_WRKSUBDIR=	yes

.include "${.CURDIR}/../../devel/bugzilla42/Makefile.common"

LANGDIR=	${WWWDIR}/template/de

do-install:
	@-${MKDIR} ${LANGDIR}
	@(cd ${WRKSRC}/de && ${COPYTREE_SHARE} . ${LANGDIR})
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

# Maintainer
plist: patch
	@( cd ${WRKDIR}/ && ${FIND} de -type f | ${AWK} '{print "%%WWWDIR%%/template/"$$1}' | ${SORT} > ${PLIST}.new )
	@( cd ${WRKDIR}/ && ${FIND} de -type d | ${AWK} '{print "@dirrmtry %%WWWDIR%%/template/"$$1}' | ${SORT} -r >> ${PLIST}.new )
	@if ${DIFF} -u ${PLIST} ${PLIST}.new ; then \
		${ECHO_MSG} no pkg-plist changes; \
		${RM} ${PLIST}.new ; \
	fi

.include <bsd.port.mk>
