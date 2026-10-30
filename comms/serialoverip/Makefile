PORTNAME=	serialoverip
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	comms net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}
DISTNAME=	${PORTNAME}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Transport of serial interfaces over UDP/IP
WWW=		https://www.sourceforge.net/projects/serialoverip/

LICENSE=	GPLv2

DEPRECATED=	Hasn't been touched in 24yrs. Too niche in todays world.
EXPIRATION_DATE=	2026-12-31

USES=		tar:tgz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	sbin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
