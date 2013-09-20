# Created by: Michael C . Wu <keichii@iteration.net>
# $FreeBSD$

PORTNAME=	auto-tw-l10n
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic localization for Traditional Chinese locale

NO_BUILD=	yes
USE_XZ=		yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

NO_STAGE=	yes
pre-install:
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${MV} ${WRKSRC}/make.conf.in ${WRKSRC}/make.conf

do-install:
	${MKDIR} ${PREFIX}/share/skel/zh_TW.UTF-8/
	${CP} ${WRKSRC}/* ${PREFIX}/share/skel/zh_TW.UTF-8/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
