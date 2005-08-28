# New ports collection makefile for:    rar
# Date created:         15 May 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	rar
PORTVERSION=	3.50
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://files1.rarlab.com/rar/ \
		http://files2.rarlab.com/rar/ \
		http://files3.rarlab.com/rar/ \
		http://files4.rarlab.com/rar/ \
		http://files5.rarlab.com/rar/ \
		http://files6.rarlab.com/rar/
DISTNAME=	rarbsd-3.5.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File archiver (binary port)

ONLY_FOR_ARCHS=	i386
NO_PACKAGE=	Only unmodified original package can be distributed
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=is unsupported on versions prior to FreeBSD 5.3
.endif

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar
	cd ${WRKSRC} && \
		${INSTALL_MAN} rar.txt ${PREFIX}/man/cat1/rar.1 && \
		${INSTALL_DATA} rarfiles.lst \
			${PREFIX}/etc && \
		${INSTALL_DATA} default.sfx \
			${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} technote.txt license.txt \
				order.htm readme.txt whatsnew.txt \
				file_id.diz \
			${DOCSDIR}
.endif

.include <bsd.port.post.mk>
