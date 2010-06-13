# New ports collection makefile for:	ftpcopy
# Date created:				5 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftpcopy
PORTVERSION=	0.6.7
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://www.ohse.de/uwe/ftpcopy/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Command line ftp tools for listing and mirroring

USE_PERL5_BUILD=	yes

WRKSRC=		${WRKDIR}/web/${DISTNAME}

NO_SIZE=	yes	# mastersite doesn't report size
MAN1=		ftpcopy.1 ftpcp.1 ftpls.1

pre-build:
	${ECHO} "${CC}" >${WRKSRC}/src/conf-cc
	${ECHO} "${CPPFLAGS} ${CFLAGS}" >${WRKSRC}/src/conf-cflags
	${ECHO} "${LDFLAGS}" >${WRKSRC}/src/conf-ldflags

do-install:
	cd ${WRKSRC}/compile && \
		${INSTALL_PROGRAM} ftpcopy ftpls ${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1 && \
		${INSTALL_SCRIPT} ftpcp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && \
	cd ${WRKSRC}/compile && \
		${INSTALL_DATA} ChangeLog NEWS \
			README THANKS ftpcopy.html ftpls.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
