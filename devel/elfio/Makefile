# ex:ts=8
# New ports collection makefile for:	elfio
# Date created:			Jul 26, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ELFIO
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog README
DOCS2=		elf11g.zip tutorial.docbook tutorial.pdf

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${DOCS2}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
