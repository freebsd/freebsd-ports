# Created by: Aldis Berjoza <graudeejs@gmail.com>
# $FreeBSD$

PORTNAME=	shairport
PORTVERSION=	1.1.1
CATEGORIES=	audio

MAINTAINER=	miks.mikelsons@gmail.com
COMMENT=	Airtunes emulator

LIB_DEPENDS=	libao.so:audio/libao
RUN_DEPENDS=	avahi-publish-service:net/avahi-app

DEPRECATED=	Officially unmaintained upstream. Use audio/shairport-sync instead
EXPIRATION_DATE=2017-11-28

USES=		gmake pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	abrasive

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=	PERL=${PERL}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${ECHO_CMD} '"'${PORTVERSION}'"' > ${WRKSRC}/version.h

do-install:
	cd ${WRKSRC} ; ${GMAKE} PREFIX=${STAGEDIR}${PREFIX} install
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/shairport

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
