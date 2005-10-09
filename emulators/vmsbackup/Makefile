# New ports collection makefile for:	vmsbackup
# Date created:		18 Apr 1994
# Whom:			Jonathan M. Bresler (jmb)
#
# $FreeBSD$
#

PORTNAME=	vmsbackup
PORTVERSION=	4.0
CATEGORIES=	emulators sysutils
MASTER_SITES=	#
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reads VMS BACKUP tapes

BROKEN=		"distfile disappeared"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2005-12-09

MAN1=		vmsbackup.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/vmsbackup
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 -f
USE_REINPLACE=  yes

post-patch:
	@${REINPLACE_CMD} -e 's#gets(ans);#fgets(ans, 80, stdin);#' ${WRKSRC}/vmsbackup.c
	@${REINPLACE_CMD} -e 's#"getopt.h"#<unistd.h>#' ${WRKSRC}/getoptmain.c

.include <bsd.port.mk>
