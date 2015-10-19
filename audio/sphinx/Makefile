# Created by: trevor
# $FreeBSD$

PORTNAME=	sphinx
PORTVERSION=	2.0.4
PORTREVISION=	3
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmu${PORTNAME}/${PORTNAME}2/0.4
DISTNAME=	sphinx2-0.4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USES=		gmake libtool shebangfix
SHEBANG_FILES=	scripts/sphinx2-demo.in
perl_OLD_CMD=	"@PERL@ -w"

# contains i386 sound code
ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e 's:<malloc.h>:<stdlib.h>:g' \
		${WRKSRC}/src/libsphinx2/CM_funcs.c	\
		${WRKSRC}/src/libsphinx2/hash.c	\
		${WRKSRC}/src/libsphinx2/list.c	\
		${WRKSRC}/src/libsphinx2/salloc.c

post-build:
	${ECHO_CMD} "*** WARNING ***"				 > ${PKGMESSAGE}
	${ECHO_CMD} "The sphinx 2 port/package has not had"	>> ${PKGMESSAGE}
	${ECHO_CMD} "proper testing or source review by the"	>> ${PKGMESSAGE}
	${ECHO_CMD} "FreeBSD maintainer."			>> ${PKGMESSAGE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsphinx2*.so

.include <bsd.port.mk>
