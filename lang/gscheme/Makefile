PORTNAME=	gscheme
PORTVERSION=	0.6
PORTREVISION=	11
CATEGORIES=	lang gnustep
MASTER_SITES=	http://www.gnustep.it/marko/GScheme/ \
		LOCAL/dinoex
DISTNAME=	GScheme
DIST_SUBDIR=	repacked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep-aware scheme interpreter
WWW=		http://www.gnustep.it/marko/GScheme/index.html

LICENSE=	GPLv2+

USES=		gnustep tar:tgz
USE_GNUSTEP=	back build

post-patch:
	@${REINPLACE_CMD} -e 's|setMark:|setMarkScheme:|' \
		${WRKSRC}/SchemeTypes.h ${WRKSRC}/SchemeTypes.m

post-install:
	${RM} ${STAGEDIR}${GNUSTEP_PREFIX}/System/Applications/GScheme.app/Resources/library.scm~
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GScheme.app/GScheme

.include <bsd.port.mk>
