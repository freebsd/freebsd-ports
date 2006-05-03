# New ports collection makefile for:	TASM TO AT&T asm
# Date created:		Thu Dec 22 14:46:11 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ta2as
PORTVERSION=	0.8
CATEGORIES=	converters devel
MASTER_SITES=	ftp://ftp.delorie.com/pub/djgpp/contrib/ \
		ftp://x2ftp.oulu.fi/pub/msdos/programming/convert/
DISTNAME=	ta2asv${PORTVERSION:S/.//}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	TASM to AT&T asm syntax converter (GNU AS)

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

EXTRACT_BEFORE_ARGS=	-q -a -L

PLIST_FILES=	bin/${PORTNAME}

.ifndef(NOPORTDOCS)
PORTDOCS=	readme.doc
.endif

post-extract:
	@${CP} ${FILESDIR}/strtolower.c ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|stricmp|strcasecmp|' \
		-e 's|strnicmp|strncasecmp|' \
		-e 's|strlwr|strtolower|' \
		${WRKSRC}/${PORTNAME}.c

do-build:
	@cd ${WRKSRC} && \
		${CC} ${CFLAGS} \
		-s meen.c strtolower.c ta2as.c \
		-o ${PORTNAME}

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.doc ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin

.include <bsd.port.mk>
