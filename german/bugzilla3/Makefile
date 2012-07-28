# New ports collection makefile for:	de-bugzilla
# Date created:		2011-06-11
# Whom:			Olli Hauer <ohauer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
PORTVERSION=	3.6.8
PORTREVISION=	1
CATEGORIES=	german
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=bugzilla-de/${PORTVERSION:R}/${PORTVERSION}
DISTNAME=	germzilla-${PORTVERSION}-1.utf-8

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	German localization for Bugzilla

RUN_DEPENDS=	bugzilla>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla3

LATEST_LINK=	${PKGNAMEPREFIX}bugzilla3

NO_WRKSUBDIR=	yes

.include "${.CURDIR}/../../devel/bugzilla3/Makefile.common"

LANGDIR=	${WWWDIR}/template/de

# german template checks the bugzilla version number and displays
# non supported bugzilla version, however there are no relevant
# changes in the template between 3.6.8 and 3.6.10
post-patch:
	@${SED} -i '' -e 's|3.6.8|3.6.10|' ${WRKDIR}/de/default/global/gzversion.html.tmpl
	@${FIND} ${WRKDIR}/ -name \*.orig -delete

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
