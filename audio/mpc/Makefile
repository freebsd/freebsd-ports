# New ports collection makefile for:	mpc
# Date created:		Oct 02 2003
# Whom:			Mark Reidel <ports@mark.reidle.info>
#
# $FreeBSD$
#

PORTNAME=	mpc
PORTVERSION=	0.15
CATEGORIES=	audio ipv6
MASTER_SITES=	SF/musicpd/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Command line client for the musicpd

OPTIONS=	ICONV "Support for international characters" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PORTDOCS=	AUTHORS README NEWS

PLIST_FILES=	bin/${PORTNAME} %%PORTEXAMPLES%%%%EXAMPLESDIR%%/${PORTNAME}-bashrc
PLIST_DIRS=	%%PORTEXAMPLES%%%%EXAMPLESDIR%%

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

.ifdef(WITHOUT_ICONV)
CONFIGURE_ARGS+=--disable-iconv
.else
USE_ICONV=	yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}-bashrc ${EXAMPLESDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
