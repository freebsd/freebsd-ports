# Created by: trevor
# $FreeBSD$

PORTNAME=	bin86
PORTVERSION=	0.16.19
CATEGORIES=	devel
MASTER_SITES=	http://www.debath.co.uk/dev86/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	16-bit assembler and loader

OPTIONS_DEFINE=	DOCS


MAN1=		as86.1 ld86.1
PORTDOCS=	ChangeLog README README-0.4
PLIST_FILES=	${BINS:C/..\//bin\//g}

CONFLICTS=	bcc-[0-9]* dev86-[0-9]*

BINS=		as/as86 ld/ld86 ld/objchop ld/catimage ld/objdump86

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/*1 ${MAN1PREFIX}/man/man1
.for i in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
