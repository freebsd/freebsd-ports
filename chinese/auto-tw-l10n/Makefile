# New ports collection makefile for:	zh-auto-tw-l10n
# Date created:		7 Oct 2000
# Whom:			"Michael C . Wu" <keichii@iteration.net>
#
# $FreeBSD$
#

PORTNAME=	auto-tw-l10n
PORTVERSION=	1.13
CATEGORIES=	chinese
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The automatic localization for Traditional Chinese zh_TW.UTF-8 locale

RUN_DEPENDS=	${FASTEST_CVSUP}:${PORTSDIR}/sysutils/fastest_cvsup

NO_BUILD=	yes
USE_XZ=		yes

PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-install pkg-message
SUB_LIST=	PREFIX=${PREFIX} ZONE=${ZONE} SOURCE_DIR=${WRKSRC} \
		WRKDIR=${WRKDIR} FASTEST_CVSUP=${FASTEST_CVSUP}

FASTEST_CVSUP?=	${LOCALBASE}/bin/fastest_cvsup
ZONE?=		tw

pre-install:
	@${SH} ${PKGINSTALL}
	@${FIND} ${WRKSRC} -name "*.in" -delete

do-install:
	${MKDIR} ${PREFIX}/share/skel/zh_TW.UTF-8/
	${CP} ${WRKSRC}/* ${PREFIX}/share/skel/zh_TW.UTF-8/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
