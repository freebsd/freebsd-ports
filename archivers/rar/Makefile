# New ports collection makefile for:    rar
# Date created:         15 May 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	rar
PORTVERSION=	3.51
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://files.rarlab.com/rar/ \
		http://files2.rarlab.com/rar/
DISTNAME=	rarbsd-3.5.1

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	File archiver (binary port)

IA32_BINARY_PORT=	YES
NO_PACKAGE=	Only unmodified original package can be distributed
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	is unsupported on versions prior to FreeBSD 5.3
.endif

.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${PREFIX}/man/cat1/rar.1
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in technote.txt license.txt order.htm readme.txt whatsnew.txt file_id.diz
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
