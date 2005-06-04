# New ports collection makefile for:	httperf
# Date created:		28 Jul 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	httperf
PORTVERSION=	0.8
CATEGORIES=	benchmarks www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for measuring webserver performance

USE_OPENSSL=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	LIBUTIL_OBJS=ssl_writev.o \
		exec_prefix=${PREFIX}

PLIST_FILES=	bin/httperf
.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog NEWS README TODO
.endif
MAN1=		httperf.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
