#
# New ports collection makefile for:	fpl
# Date created:			02/01/2003
# Whom:				Dominic Marks <dom@cus.org.uk>
#
# $FreeBSD$
#

PORTNAME=	fpl
PORTVERSION=	14.12
CATEGORIES=	lang
MASTER_SITES=	ftp://ich.bin.kein.hoschi.de/fpl/ \
		http://www.cus.org.uk/~dom/distfiles/fpl/

MAINTAINER=	d.marks@student.umist.ac.uk
COMMENT=	An interpreted script/macro language

BROKEN=		Does not fetch

ALL_TARGET=

.include <bsd.port.pre.mk>

pre-build:
	@${MV} ${WRKSRC}/src/Makefile ${WRKSRC}/src/Makefile.old
	@${MV} ${WRKSRC}/src/Makefile.FreeBSD ${WRKSRC}/src/Makefile

do-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/
	${INSTALL_DATA} -m 0644 \
		${WRKSRC}/src/libfpl.a \
		${WRKSRC}/src/libent.a \
		${WRKSRC}/src/liballoc.a \
			${PREFIX}/lib/${PORTNAME}/

.include <bsd.port.post.mk>
