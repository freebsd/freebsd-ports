# New ports collection makefile for:    rar
# Date created:         15 May 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	rar
PORTVERSION=    3.30
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=   http://files10.rarlab.com/rar/
DISTNAME=       rarbsd-3.3.0

MAINTAINER=	ache@FreeBSD.org
COMMENT=	File archiver (binary port)

CAT1=		rar.1

CONFLICTS=      unrar-*
ONLY_FOR_ARCHS=	i386
NO_PACKAGE=	Only unmodified original package can be distributed
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/unrar
	cd ${WRKSRC} && \
		${INSTALL_MAN} rar.txt ${PREFIX}/man/cat1/rar.1 && \
		${INSTALL_DATA} rarfiles.lst \
			${PREFIX}/etc && \
		${INSTALL_DATA} default.sfx \
			${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} rar_faq.txt technote.txt license.txt \
				order.htm readme.txt whatsnew.txt \
				file_id.diz \
			${DOCSDIR}
.endif

.include <bsd.port.post.mk>
