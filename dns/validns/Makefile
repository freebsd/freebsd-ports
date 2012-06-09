# New ports collection makefile for:	validns
# Date created:		2012-04-25
# Whom:			Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	validns
PORTVERSION=	0.5
CATEGORIES=	dns security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A high performance DNS/DNSSEC zone validator

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	Judy.1:${PORTSDIR}/devel/judy

ALL_TARGET=

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	Changes README installation.mdwn notes.mdwn \
		technical-notes.mdwn todo.mdwn usage.mdwn

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${MAN1:S,^,${WRKSRC}/,} ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
