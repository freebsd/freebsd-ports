PORTNAME=	sphinx
PORTVERSION=	2.0.4
PORTREVISION=	3
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmu${PORTNAME}/${PORTNAME}2/0.4
DISTNAME=	sphinx2-0.4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system
WWW=		http://cmusphinx.sourceforge.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream advises to use audio/pocketsphinx
EXPIRATION_DATE=	2024-01-25
# contains i386 sound code
ONLY_FOR_ARCHS=	i386

USES=		dos2unix gmake libtool shebangfix
DOS2UNIX_FILES=	src/libsphinx2fe/fe_sigproc.c
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/sphinx2-demo.in
perl_OLD_CMD=	"@PERL@ -w"

GNU_CONFIGURE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

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
