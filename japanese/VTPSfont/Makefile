# New ports collection makefile for:	VTPSfont
# Version required:	1.3
# Date created:		99/06/15
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	VTPSfont-1.3
PKGNAME=	ja-VTPSfont-1.3
CATEGORIES=	japanese print
MASTER_SITES=	http://ftp.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/tt/
EXTRACT_SUFX=	''

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash1

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
		@${RM} -rf ${WRKDIR}
		@${MKDIR} ${WRKDIR}
		@for file in ${DISTFILES}; do \
			${CP} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${WRKSRC}; \
		done

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
			${PREFIX}/bin/VTPSfont

.include <bsd.port.mk>
