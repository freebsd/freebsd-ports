# $FreeBSD$

PORTNAME=	gscheme
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	lang gnustep
MASTER_SITES=	http://www.gnustep.it/marko/GScheme/ \
		LOCAL/dinoex
DISTNAME=	GScheme
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	repacked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep-aware scheme interpreter

LICENSE=	GPLv2 # or later

USES=		gnustep
USE_GNUSTEP=	back build

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|setMark:|setMarkScheme:|' \
		${WRKSRC}/SchemeTypes.h ${WRKSRC}/SchemeTypes.m

post-install:
	${RM} -f ${STAGEDIR}${GNUSTEP_PREFIX}/Local/Applications/GScheme.app/Resources/library.scm~
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/GScheme.app/GScheme

.include <bsd.port.mk>
