# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ftpcopy
PORTVERSION=	0.6.7
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://www.ohse.de/uwe/ftpcopy/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Command line ftp tools for listing and mirroring

BROKEN_aarch64=		fails to build: regparm is not valid on this platform
BROKEN_armv6=		fails to build: regparm is not valid on this platform
BROKEN_armv7=		fails to build: regparm is not valid on this platform

USES=		perl5
USE_PERL5=	build

WRKSRC=		${WRKDIR}/web/${DISTNAME}

OPTIONS_DEFINE=	DOCS

pre-build:
	${ECHO} "${CC}" >${WRKSRC}/src/conf-cc
	${ECHO} "${CPPFLAGS} ${CFLAGS}" >${WRKSRC}/src/conf-cflags
	${ECHO} "${LDFLAGS}" >${WRKSRC}/src/conf-ldflags

do-install:
	cd ${WRKSRC}/compile && \
		${INSTALL_PROGRAM} ftpcopy ftpls ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_MAN} *.1 ${STAGEDIR}${PREFIX}/man/man1 && \
		${INSTALL_SCRIPT} ftpcp ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	cd ${WRKSRC}/compile && \
		${INSTALL_DATA} ChangeLog NEWS \
			README THANKS ftpcopy.html ftpls.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
