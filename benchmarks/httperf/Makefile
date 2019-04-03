# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	httperf
PORTVERSION=	0.9.0.1
CATEGORIES=	benchmarks www

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Tool for measuring webserver performance

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool ssl
USE_GITHUB=	yes
GH_TAGNAME=	dcfb746
MAKE_ARGS=	LIBUTIL_OBJS=ssl_writev.o \
		exec_prefix=${PREFIX}

PLIST_FILES=	bin/httperf \
		man/man1/httperf.1.gz
PORTDOCS=	ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	error: incomplete definition of type 'struct ssl_cipher_st'
BROKEN_FreeBSD_13=	error: incomplete definition of type 'struct ssl_cipher_st'
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
