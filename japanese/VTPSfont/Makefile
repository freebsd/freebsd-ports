# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	VTPSfont
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	http://ftp.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/tt/
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create Virtual PostScript fonts produced by VFlib (Truetype fonts)

PLIST_FILES=	bin/VTPSfont
RUN_DEPENDS=	bash:shells/bash

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
		@${RM} -r ${WRKSRC}
		@${MKDIR} ${WRKSRC}
		@for file in ${DISTFILES}; do \
			${CP} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${WRKSRC}; \
		done

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
			${STAGEDIR}${PREFIX}/bin/VTPSfont

.include <bsd.port.mk>
