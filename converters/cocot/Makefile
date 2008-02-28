# New ports collection makefile for:	cocot
# Date created:		24 July 2007
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cocot
PORTVERSION=	20041220
CATEGORIES=	converters
MASTER_SITES=	http://vmi.jp/software/cygwin/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Code Converter on TTY

USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

DOCS_EN=	COPYING ChangeLog
DOCS_JA=	ChangeLog.ja README.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/ja
.endfor
.endif

.include <bsd.port.mk>
