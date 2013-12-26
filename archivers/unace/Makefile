# Created by: Joao Carlos Mendes Luis <jonny@jonny.eng.br>
# $FreeBSD$

PORTNAME=	unace
PORTVERSION=	1.2b
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	jonny@jonny.eng.br
COMMENT=	Extract, view & test ACE archives

MAKE_JOBS_UNSAFE=	yes

USES=		gmake
ALL_TARGET=	clean unace
PLIST_FILES=	bin/unace

post-patch:
	@${REINPLACE_CMD} -e "s|CFLAGS =|CFLAGS ?=|" \
			-e "s|CC =|CC ?=|" \
			-e 's|gcc $$(CFLAGS)|$${CC} $$(CFLAGS)|' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|(CHAR \* s, thead \* head, INT nopath);|(CHAR \* s, thead \* head, INT nopath, unsigned int size);|' \
			${WRKSRC}/uac_crt.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
