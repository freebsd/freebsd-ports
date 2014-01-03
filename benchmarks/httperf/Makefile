# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	httperf
PORTVERSION=	0.9.0
CATEGORIES=	benchmarks www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	A tool for measuring webserver performance

LICENSE=	GPLv2

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		gmake
MAKE_ARGS=	LIBUTIL_OBJS=ssl_writev.o \
		exec_prefix=${PREFIX}

PLIST_FILES=	bin/httperf
PORTDOCS=	ChangeLog NEWS README TODO
MAN1=		httperf.1

NO_STAGE=	yes

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

do-install:
	@${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
