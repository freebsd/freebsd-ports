# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	4.4.9
CATEGORIES=	japanese
MASTER_SITES=	http://bug-ja.org/releases/4.4/ \
		LOCAL/tota/bugzilla-ja
DISTNAME=	Bugzilla-ja-${PORTVERSION}-template

MAINTAINER=	bz-ports@FreeBSD.org
COMMENT=	Japanese localization for Bugzilla

RUN_DEPENDS=	bugzilla44>=${PORTVERSION}:devel/bugzilla44

NO_WRKSUBDIR=	yes

.include "${.CURDIR}/../../devel/bugzilla44/Makefile.common"

USES=		tar:bzip2

LANGDIR=	${WWWDIR}/template/ja

do-install:
	@-${MKDIR} ${STAGEDIR}${LANGDIR}/default
	(cd ${WRKSRC}/default && ${COPYTREE_SHARE} . ${STAGEDIR}${LANGDIR}/default)

# Maintainer
plist: patch
	@( cd ${WRKSRC}/ && ${FIND} default -type f | ${AWK} '{print "%%WWWDIR%%/template/ja/"$$1}' | ${SORT} > ${PLIST}.new )
	@if ${DIFF} -u ${PLIST} ${PLIST}.new ; then \
		${ECHO_MSG} no pkg-plist changes; \
		${RM} ${PLIST}.new ; \
	fi

.include <bsd.port.mk>
