# New ports collection makefile for:	VTPSfont
# Date created:		99/06/15
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	VTPSfont
PORTVERSION=	1.3
CATEGORIES=	japanese print
MASTER_SITES=	http://ftp.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/tt/
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create Virtual PostScript fonts produced by VFlib (Truetype fonts)

PLIST_FILES=	bin/VTPSfont
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

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
