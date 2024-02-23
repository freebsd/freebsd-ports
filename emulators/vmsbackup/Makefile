PORTNAME=	vmsbackup
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	emulators sysutils
MASTER_SITES=	LOCAL/erwin
DISTNAME=	VMSBACKUP4-1-1
EXTRACT_SUFX=	.ZIP

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reads VMS BACKUP tapes
WWW=		https://www.panix.com/~kingdon/vms/backup.html

USES=		zip
ALL_TARGET=	vmsbackup
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/vmsbackup share/man/man1/vmsbackup.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's#"getopt.h"#<unistd.h>#' ${WRKSRC}/getoptmain.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vmsbackup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vmsbackup.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
