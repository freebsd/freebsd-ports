# ex:ts=8
#
# New ports collection makefile for:	invitation_to_ruby
# Date created:			2002/08/28
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	invitation_to_ruby
PORTVERSION=	1.0.0
#PORTEPOCH=
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.one.net/pub/users/jweirich/talks/
#MASTER_SITE_SUBDIR=
#PKGNAMEPREFIX=
#PKGNAMESUFFIX=
DISTNAME=	invitationtoruby
EXTRACT_SUFX=	.tgz
#DISTFILES=
#DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
#EXTRACT_ONLY=

MAINTAINER=	freebsd-ports@FreeBSD.org

NO_BUILD=	yes

PLIST=		${WRKDIR}/plist

CPIO?=		/usr/bin/cpio
SORT?=		/usr/bin/sort

.include <bsd.port.pre.mk>

pre-install:
	${RM} -f ${PLIST}
	${ECHO_CMD} "@comment files" >> ${PLIST}
	cd ${WRKSRC}; ${FIND} . -type f | cut -c2- \
		| ${SED} 's|^|${DOCSDIR:S,${PREFIX}/,,}|' \
		| ${SORT} >> ${PLIST}
	${ECHO_CMD} "@comment directories" >> ${PLIST}
	cd ${WRKSRC}; ${FIND} . -type d | cut -c2- \
		| ${SED} 's|^|@dirrm ${DOCSDIR:S,${PREFIX}/,,}|' \
		| ${SORT} -r >> ${PLIST}

do-install:
	${RM} -fr ${DOCSDIR}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; find . | ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	${CHMOD} -R ugo-w,ugo+rX ${DOCSDIR}

.include <bsd.port.post.mk>
#EOF
