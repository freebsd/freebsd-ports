PORTNAME=	ftpsesame
PORTVERSION=	0.95
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	http://www.sentia.org/downloads/ \
		LOCAL/sem

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper for pf firewall to pass FTP protocol
WWW=		https://www.sentia.org/projects/ftpsesame/

LICENSE=	ISCL

PLIST_FILES=	bin/ftpsesame share/man/man8/ftpsesame.8.gz
USE_RC_SUBR=	ftpsesame

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftpsesame ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ftpsesame.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
