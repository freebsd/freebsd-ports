# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	4.4.10
PORTREVISION=	1
CATEGORIES=	german
MASTER_SITES=	SF/bugzilla-de/${PORTVERSION:R}/${PORTVERSION}
DISTNAME=	${PORTNAME}-de-${PORTVERSION}-1.utf-8

MAINTAINER=	bz-ports@FreeBSD.org
COMMENT=	German localization for Bugzilla

RUN_DEPENDS=	bugzilla44>=${PORTVERSION}:devel/bugzilla44

NO_WRKSUBDIR=	yes

# adjust BZ_REVNUM if bugzilla revision was incremented and there are no
# changes in bugzilla/templates/en. If not used simply comment the line.
BZ_REVNUM=	11

.include "${.CURDIR}/../../devel/bugzilla44/Makefile.common"

LANGDIR=	${WWWDIR}/template/de

.if defined(BZ_REVNUM) && !empty(BZ_REVNUM)
post-patch:
	${REINPLACE_CMD} -e 's/${PORTVERSION}/${PORTVERSION:R}.${BZ_REVNUM}/' \
		${WRKSRC}/de/default/global/gzversion.html.tmpl
	@${FIND} ${WRKSRC}/de/default/ -type f \( -name \*.orig -o -name \*.bak \) -delete
.endif

do-install:
	@-${MKDIR} ${STAGEDIR}${LANGDIR}
	@(cd ${WRKSRC}/de && ${COPYTREE_SHARE} . ${STAGEDIR}${LANGDIR})

# Maintainer
plist: patch
	@( cd ${WRKDIR}/ && ${FIND} de -type f | ${AWK} '{print "%%WWWDIR%%/template/"$$1}' | ${SORT} > ${PLIST}.new )
	@if ${DIFF} -u ${PLIST} ${PLIST}.new ; then \
		${ECHO_MSG} no pkg-plist changes; \
		${RM} ${PLIST}.new ; \
	fi

.include <bsd.port.mk>
