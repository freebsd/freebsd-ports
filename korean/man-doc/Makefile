# New ports collection makefile for:	ko-man-doc
# Date created:			19 November 2002
# Whom:				Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	man
PORTVERSION=	021120
CATEGORIES=	korean
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
MASTER_SITE_SUBDIR=	perky
PKGNAMESUFFIX=	-doc
DISTNAME=	ko-man-doc-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Korean online manual pages

RUN_DEPENDS=	${LOCALBASE}/bin/groff:${PORTSDIR}/japanese/groff

post-patch:
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,gnroff,groff,g' ${WRKSRC}/scripts/kman.in > ${WRKDIR}/kman
	${RM} -rf ${WRKSRC}/scripts

do-build:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${GZIP_CMD}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/kman ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/share/man/ko_KR.eucKR
	${TAR} -C ${WRKSRC} -cf - . | \
		${TAR} -C ${PREFIX}/share/man/ko_KR.eucKR -xf -

.include <bsd.port.mk>
