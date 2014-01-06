# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	httperf
PORTVERSION=	0.9.0
CATEGORIES=	benchmarks www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Tool for measuring webserver performance

LICENSE=	GPLv2

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		gmake
MAKE_ARGS=	LIBUTIL_OBJS=ssl_writev.o \
		exec_prefix=${PREFIX}

PLIST_FILES=	bin/httperf \
		man/man1/httperf.1.gz
PORTDOCS=	ChangeLog NEWS README TODO

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
