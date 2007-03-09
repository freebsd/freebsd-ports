# New ports collection makefile for:	fapg
# Date created:		2006-06-22
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fapg
PORTVERSION=	0.37
CATEGORIES=	audio
MASTER_SITES=	http://royale.zerezo.com/${PORTNAME}/

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Fast Audio Playlist Generator

MAKE_ARGS+=	CC=${CC}
USE_GETOPT_LONG=yes

MAN1=		fapg.1

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's,g2,g2 -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib -lgnugetopt,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '32 s,<,\",; 32 s,>,\",' \
		${WRKSRC}/fapg.c
	@${CP} ${FILESDIR}/getopt.h ${WRKSRC}
.endif

do-build:
	@cd ${WRKSRC} && ${MAKE} ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${TARGETDIR}/bin
	${INSTALL_MAN} ${WRKSRC}/fapg.1 ${MAN1PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in COPYING README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
