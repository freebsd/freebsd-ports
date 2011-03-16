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
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	invitationtoruby
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Talk given by Jim Weirich, a brief introduction to Ruby

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_BUILD=	yes
NO_CDROM=	\
"no commercial use--see \<URL:http://creativecommons.org/licenses/by-nc/1.0/\>"

PLIST=		${WRKDIR}/plist

.include <bsd.port.pre.mk>

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKSRC}; ${FIND} . -type f | ${CUT} -c2- \
		| ${SED} 's|^|${DOCSDIR:S,${PREFIX}/,,}|' \
		| ${SORT} >> ${PLIST}
	cd ${WRKSRC}; ${FIND} . -type d | ${CUT} -c2- \
		| ${SED} 's|^|@dirrm ${DOCSDIR:S,${PREFIX}/,,}|' \
		| ${SORT} -r >> ${PLIST}

do-install:
	${RM} -fr ${DOCSDIR}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	${CHMOD} -R ugo-w,ugo+rX ${DOCSDIR}

.include <bsd.port.post.mk>
