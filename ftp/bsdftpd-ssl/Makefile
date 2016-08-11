# Created by: Nick Leuta
# $FreeBSD$

PORTNAME=	bsdftpd-ssl
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	http://www.sourcefiles.org/System/Daemons/FTP/ \
		LOCAL/sunpoet

MAINTAINER=	skynick@mail.sc.ru
COMMENT=	Secure FTP client/server with TLS/SSL support

USE_OPENSSL=	yes
MAKE_ENV+=	OBJFORMAT=elf
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	SERVER DOCS EXAMPLES
SERVER_DESC=	Build/install FTP server as well
OPTIONS_SUB=	yes
USE_RC_SUBR=	${PORTNAME}

# in case people still have CLIENT_ONLY defined...
.if !defined(CLIENT_ONLY)
OPTIONS_DEFAULT=SERVER
.endif

# explicitly link against libpam to support external toolchains.
LDFLAGS+=	-lpam

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSERVER} && ${PORT_OPTIONS:MEXAMPLES}
SUB_FILES=	pkg-message
.endif

post-patch:
	${MV} ${WRKSRC}/docs/README ${WRKSRC}/docs/README-docs

do-configure:
	(cd ${WRKSRC} && ./config.sh FreeBSD) || true

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/port
	${DO_MAKE_BUILD} -C ${WRKSRC}/ftp
.if ${PORT_OPTIONS:MSERVER}
	${DO_MAKE_BUILD} -C ${WRKSRC}/ftpd
.endif

do-install:
# Client part
	${INSTALL_PROGRAM} ${WRKSRC}/ftp/ftps ${STAGEDIR}${PREFIX}/bin/ftps
	${INSTALL_MAN} ${WRKSRC}/ftp/ftps.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/ftps.1.gz
# Server part
.if ${PORT_OPTIONS:MSERVER}
	${INSTALL_PROGRAM} ${WRKSRC}/ftpd/ftpd ${STAGEDIR}${PREFIX}/libexec/ftpd
	${INSTALL_MAN} ${WRKSRC}/ftpd/ftpchroot.5.gz ${STAGEDIR}${MANPREFIX}/man/man5/ftpchroot.5.gz
	${INSTALL_MAN} ${WRKSRC}/ftpd/xferlog.5.gz ${STAGEDIR}${MANPREFIX}/man/man5/xferlog.5.gz
	${INSTALL_MAN} ${WRKSRC}/ftpd/ftpd.8.gz ${STAGEDIR}${MANPREFIX}/man/man8/ftpd.8.gz
	${LN} -s ftpchroot.5.gz ${STAGEDIR}${MANPREFIX}/man/man5/ftpchroot-ssl.5.gz
	${LN} -s ftpd.8.gz ${STAGEDIR}${MANPREFIX}/man/man8/ftpd-ssl.8.gz
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
. for file in COPYRIGHT README INSTALL ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
. endfor

.if ${PORT_OPTIONS:MSERVER} && ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/cert
	${INSTALL_SCRIPT} ${WRKSRC}/cert/* ${STAGEDIR}${EXAMPLESDIR}/cert
. for file in README.examples ftpchroot ftpusers rc_conf_d.bsdftpd_ssl
	${INSTALL_DATA} ${FILESDIR}/${file} ${STAGEDIR}${EXAMPLESDIR}
. endfor
.endif

.include <bsd.port.mk>
