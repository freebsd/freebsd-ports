# New ports collection makefile for:	bin86
# Date created:				2000-10-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	bin86
PORTVERSION=	0.16.16
CATEGORIES=	devel
MASTER_SITES=	http://www.cix.co.uk/~mayday/dev86/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	16-bit assembler and loader (conflicts with devel/bcc)

BINS=		as/as86 ld/ld86 ld/objchop ld/catimage ld/objdump86
CONFLICTS=	bcc-*
DOCS=		ChangeLog README README-0.4
DOCDIR=		share/doc/${PORTNAME}
MAN1=		as86.1 ld86.1
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/pkg-plist

post-extract:
	${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${CHMOD} 644

pre-install:
	${RM} -f ${PLIST}
.for i in ${BINS}
	${ECHO_CMD} bin/`${BASENAME} ${i}` >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} "@dirrm " ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/*1 ${PREFIX}/man/man1
.for i in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
