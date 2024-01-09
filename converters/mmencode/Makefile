PORTNAME=	mmencode
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/mail/metamail/
DISTNAME=	mm${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate to and from mail-oriented encoding formats

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${DISTNAME}/src/metamail

PLIST_FILES=	bin/mmencode bin/mimencode \
		share/man/man1/mmencode.1.gz \
		share/man/man1/mimencode.1.gz

USES=		tar:Z
ALL_TARGET=	mmencode
MAKE_ARGS=	CFLAGS="${CFLAGS}"

CONFLICTS_INSTALL=	elm metamail # bin/mimencode bin/mmencode

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmencode ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../man/mmencode.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	cd ${STAGEDIR}${PREFIX}/share/man/man1 && ${LN} -s mmencode.1 mimencode.1
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s mmencode mimencode

.include <bsd.port.mk>
