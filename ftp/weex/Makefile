# New ports collection makefile for:	weex
# Date created:				8 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	weex
PORTVERSION=	2.6.1.5
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A non-interactive FTP client

GNU_CONFIGURE=	yes
MANCOMPRESSED=	no

PORTDOCS=	ChangeLog README
MAN1=		weex.1

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS.*\)debian|\1|' \
		${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.weexrc ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

NOT_FOR_ARCHS=	amd64

.include <bsd.port.mk>
