# New ports collection makefile for:   cel
# Date created:        1 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cel
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.redwoodsoft.com/cel/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small, simple prototype-based OO language

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes

PORTDOCS=	CoreArchitecture.html DefaultProtos Linker.html \
		Logs.html ProtoLanguage.html README SimpleDataFormat.html \
		Threads activation.html stackframe structure.html todo.html
PLIST_FILES=	bin/cel

.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC}; ${SH} ./config.unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vm/cel ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cel
.for F in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/$F ${PREFIX}/share/doc/cel
.endfor
.endif

.include <bsd.port.post.mk>
