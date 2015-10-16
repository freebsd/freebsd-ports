# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	b2
PORTVERSION=	0.2.4
CATEGORIES=	devel
MASTER_SITES=	https://www.backblaze.com/b2/docs/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Command Line Interface for Backblaze's B2 storage service

LICENSE=	MIT

USES=		python:2.6+ shebangfix
SHEBANG_FILES=	b2
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
