# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	4.4.5
CATEGORIES=	german
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=bugzilla-de/${PORTVERSION:R}/${PORTVERSION}
DISTNAME=	germzilla-${PORTVERSION}-1.utf-8

MAINTAINER=	bugzilla@FreeBSD.org
COMMENT=	German localization for Bugzilla

RUN_DEPENDS=	bugzilla44>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla44

NO_WRKSUBDIR=	yes

# adjust BZ_REVNUM if bugzilla revision was incremented and there are no
# changes in bugzilla/templates/en. If not used simply comment the line.
#BZ_REVNUM=	5

.include "${.CURDIR}/../../devel/bugzilla44/Makefile.common"

LANGDIR=	${WWWDIR}/template/de

.if defined(BZ_REVNUM) && !empty(BZ_REVNUM)
post-patch:
	${REINPLACE_CMD} -e 's/${PORTVERSION}/${PORTVERSION:R}.${BZ_REVNUM}/' \
		${WRKDIR}/de/default/global/gzversion.html.tmpl
	@${FIND} ${WRKDIR}/de/default/ -type f \( -name \*.orig -o -name \*.bak \) -delete
.endif

do-install:
	@-${MKDIR} ${STAGEDIR}${LANGDIR}
	@(cd ${WRKSRC}/de && ${COPYTREE_SHARE} . ${STAGEDIR}${LANGDIR})

# Maintainer
plist: patch
	@( cd ${WRKDIR}/ && ${FIND} de -type f | ${AWK} '{print "%%WWWDIR%%/template/"$$1}' | ${SORT} > ${PLIST}.new )
	@( cd ${WRKDIR}/ && ${FIND} de -type d | ${AWK} '{print "@dirrmtry %%WWWDIR%%/template/"$$1}' | ${SORT} -r >> ${PLIST}.new )
	@if ${DIFF} -u ${PLIST} ${PLIST}.new ; then \
		${ECHO_MSG} no pkg-plist changes; \
		${RM} ${PLIST}.new ; \
	fi

.include <bsd.port.mk>
