# New ports collection makefile for:	zh-auto-tw-l10n
# Date created:		7 Oct 2000
# Whom:			"Michael C . Wu" <keichii@iteration.net>
#
# $FreeBSD$

PORTNAME=	auto-tw-l10n
PORTVERSION=	1.6
CATEGORIES=	chinese
MASTER_SITES=	http://bbs.ilc.edu.tw/~chinsan/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/auto-tw-l10n/
DISTNAME=	zh-${PORTNAME}-${PORTVERSION}

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	The automatic localization for Traditional Chinese zh_TW.Big5 locale

RUN_DEPENDS=	${FASTEST_CVSUP}:${PORTSDIR}/sysutils/fastest_cvsup

USE_REINPLACE=	yes
NO_BUILD=	yes

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
	@# Temporary hack before adduser is modified
	@#	For future adduser
	@#	adduser -l10n -v $HOME
	${MKDIR} ${PREFIX}/share/skel/zh_TW.Big5
	${CP} ${WRKSRC}/* ${PREFIX}/share/skel/zh_TW.Big5

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
