# New ports collection makefile for:   cel
# Date created:        1 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cel
PORTVERSION=	0.6
CATEGORIES=	lang
MASTER_SITES=	http://www.redwoodsoft.com/cel/
EXTRACT_SUFX=	.tgz

MAINTAINER=	greid@ukug.uk.freebsd.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes

DOCFILES=	CoreArchitecture.html DefaultProtos Linker.html \
		Logs.html ProtoLanguage.html README SimpleDataFormat.html \
		Threads activation.html stackframe structure.html todo.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vm/cel ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cel
.for F in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/$F ${PREFIX}/share/doc/cel
.endfor
.endif

.include <bsd.port.mk>
