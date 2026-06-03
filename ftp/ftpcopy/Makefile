PORTNAME=	ftpcopy
PORTVERSION=	0.6.7
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://www.ohse.de/uwe/ftpcopy/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Command line FTP tools for listing and mirroring
WWW=		https://www.ohse.de/uwe/ftpcopy.html

LICENSE=	GPLv2

USES=		perl5
USE_PERL5=	build

WRKSRC=		${WRKDIR}/web/${DISTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-build:
	${ECHO} "${CC}" >${WRKSRC}/src/conf-cc
	${ECHO} "${CPPFLAGS} ${CFLAGS}" >${WRKSRC}/src/conf-cflags
	${ECHO} "${LDFLAGS}" >${WRKSRC}/src/conf-ldflags

do-install:
	cd ${WRKSRC}/compile && \
		${INSTALL_PROGRAM} ftpcopy ftpls ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_MAN} *.1 ${STAGEDIR}${PREFIX}/share/man/man1 && \
		${INSTALL_SCRIPT} ftpcp ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	cd ${WRKSRC}/compile && \
		${INSTALL_DATA} ChangeLog NEWS \
			README THANKS ftpcopy.html ftpls.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
