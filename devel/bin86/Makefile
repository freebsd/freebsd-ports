# New ports collection makefile for:	bin86
# Date created:				2000-10-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	bin86
PORTVERSION=	0.16.17
CATEGORIES=	devel
MASTER_SITES=	http://homepage.ntlworld.com/robert.debath/dev86/

MAINTAINER=	shaun@inerd.com
COMMENT=	16-bit assembler and loader (conflicts with devel/bcc)

BINS=		as/as86 ld/ld86 ld/objchop ld/catimage ld/objdump86
CONFLICTS=	bcc-[0-9]*
PORTDOCS=	ChangeLog README README-0.4
MAN1=		as86.1 ld86.1

ONLY_FOR_ARCHS=	i386

PLIST_FILES+=	${BINS:C/..\//bin\//g}

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/*1 ${MAN1PREFIX}/man/man1
.for i in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
