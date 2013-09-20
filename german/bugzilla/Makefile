# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	4.0.10
CATEGORIES=	german
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=bugzilla-de/${PORTVERSION:R}/${PORTVERSION}
DISTNAME=	germzilla-${PORTVERSION}-1.utf-8

MAINTAINER=	bugzilla@FreeBSD.org
COMMENT=	German localization for Bugzilla

RUN_DEPENDS=	bugzilla>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla

LATEST_LINK=	${PKGNAMEPREFIX}bugzilla

NO_WRKSUBDIR=	yes

NO_STAGE=	yes
.include "${.CURDIR}/../../devel/bugzilla/Makefile.common"

LANGDIR=	${WWWDIR}/template/de

#post-patch:
#	@${REINPLACE_CMD} -i '' -e 's/4.0.8/4.0.9/' \
#		${WRKDIR}/de/default/global/gzversion.html.tmpl
#	@${FIND} ${WRKDIR}/de/default/ -type f \( -name \*.orig -o -name \*.bak \) -delete

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
