# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	man
PORTVERSION=	021120
PORTREVISION=	3
CATEGORIES=	korean
MASTER_SITES=	LOCAL/perky \
		http://people.freebsd.org/~perky/distfiles/
PKGNAMESUFFIX=	-doc
DISTNAME=	ko-man-doc-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Korean online manual pages

RUN_DEPENDS=	${LOCALBASE}/bin/groff:japanese/groff

post-patch:
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,gnroff,groff,g' ${WRKSRC}/scripts/kman.in > ${WRKDIR}/kman
	${RM} -rf ${WRKSRC}/scripts

do-build:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${GZIP_CMD}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/kman ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ko_KR.eucKR
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/man/ko_KR.eucKR)

.include <bsd.port.mk>
