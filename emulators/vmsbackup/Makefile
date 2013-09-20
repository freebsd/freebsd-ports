# Created by: Jonathan M. Bresler (jmb)
# $FreeBSD$

PORTNAME=	vmsbackup
PORTVERSION=	4.1.1
CATEGORIES=	emulators sysutils
MASTER_SITES=	http://dl.droso.net/FreeBSD/distfiles/ \
		http://freebsd.t-hosting.hu/vmsbackup/ \
		${MASTER_SITE_LOCAL:S/$/erwin\//}
DISTNAME=	VMSBACKUP4-1-1
EXTRACT_SUFX=	.ZIP

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reads VMS BACKUP tapes

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
ALL_TARGET=	vmsbackup

PLIST_FILES=	bin/vmsbackup
MAN1=		vmsbackup.1
MANCOMPRESSED=	no

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKSRC}
	${UNZIP_CMD} ${DISTDIR}/${DISTNAME} -d ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's#gets(ans);#fgets(ans, 80, stdin);#' ${WRKSRC}/vmsbackup.c
	@${REINPLACE_CMD} -e 's#"getopt.h"#<unistd.h>#' ${WRKSRC}/getoptmain.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vmsbackup ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
