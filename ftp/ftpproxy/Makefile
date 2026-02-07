PORTNAME=	ftpproxy
DISTVERSION=	1.2.3
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		http://www.ftpproxy.org/download/older_releases/

MAINTAINER=	philippe@le-berre.com
COMMENT=	FTP proxy
WWW=		https://www.ftpproxy.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" \
		OSLIB="-lutil"
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	ftpproxy

PLIST_FILES=	etc/rc.d/ftpproxy \
		sbin/ftp.proxy \
		share/man/man1/ftp.proxy.1.gz

pre-build:
	@${REINPLACE_CMD} -e 's|^CFLAGS.*|CFLAGS=${CFLAGS} \
	     -DVERSION=\\"${PORTVERSION}\\"|' ${WRKSRC}/src/Makefile

post-build:
	${GZIP_CMD} ${WRKSRC}/doc/ftp.proxy.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftp.proxy ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/ftp.proxy.1.gz ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_SCRIPT} ${WRKDIR}/ftpproxy ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
