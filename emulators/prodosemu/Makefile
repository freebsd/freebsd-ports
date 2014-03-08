# Created by: Joel Sutton <sutton@aardvark.apana.org.au>
# $FreeBSD$

PORTNAME=	prodosemu
PORTVERSION=	0.1
CATEGORIES=	emulators
MASTER_SITES=	http://mirrors.apple2.org.za/apple2.caltech.edu/emulators/
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text based Apple IIe ProDOS emulator

RESTRICTED=	apple.rom copyright is owned by Apple and cannot be distributed.

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
PORTDOCS=	README
PLIST_FILES=	bin/prodos share/apple2/prodos-2e.rom
PLIST_DIRS=	share/apple2

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
