PORTNAME=	smbftpd
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/SmbFTPD/${PORTVERSION}	\
		http://www.twbsd.org/download/download.php?file=smbftpd/

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	FTP daemon using Samba-like share management mechanism
WWW=		https://www.twbsd.org/enu/smbftpd/index.php

USES=		cpe perl5
USE_RC_SUBR=	${PORTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	"--prefix=${PREFIX}"

MAKE_ENV+=	OSTYPE=FreeBSD

OPTIONS_DEFINE=	PGSQL SSL ICONV

ICONV_DESC=	Enable codepage to unicode conversion for UTF-8 FTP

ICONV_USES=	iconv
ICONV_CONFIGURE_WITH=	iconv
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	pgsql
SSL_CONFIGURE_WITH=		ssl

post-extract:
	${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e '/^CONFIGS = / s|\.conf|&.sample|g' ${WRKSRC}/Makefile
	cd ${WRKSRC}/conf/ && (${LS} *.conf | ${XARGS} -I % ${MV} % %.sample)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-user ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/*.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
