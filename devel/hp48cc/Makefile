# New ports collection makefile for:	hp48cc
# Date created:				Sun Aug 12 04:33:37 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	hp48cc
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SUNSITE} http://www.sigala.it/sandro/files/
MASTER_SITE_SUBDIR=	devel/lang/c

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	C-like compiler that translates input code to the HP48 RPL language

LICENSE=	GPLv2

USE_BISON=	build
GNU_CONFIGURE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
PORTEXAMPLES=	*

post-patch:
# Fix the Makefile to unbreak parallel builds
	@${REINPLACE_CMD} -e 's,(YACC),& -o parser.c, ; \
		s,(LEX),& -olexer.c, ; /mv/d' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
