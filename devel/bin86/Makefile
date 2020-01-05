# Created by: trevor
# $FreeBSD$

PORTNAME=	bin86
PORTVERSION=	0.16.21
CATEGORIES=	devel
MASTER_SITES=	http://v3.sk/~lkundrak/dev86/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	16-bit assembler and loader

BROKEN=		unfetchable

CONFLICTS=	bcc-[0-9]* dev86-[0-9]*

PLIST_FILES=	bin/as86 bin/catimage bin/ld86 bin/objchop bin/objdump86 \
		man/man1/as86.1.gz man/man1/ld86.1.gz
PORTDOCS=	ChangeLog README README-0.4

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/*1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.for prog in as/as86 ld/ld86 ld/objchop ld/catimage ld/objdump86
	${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
