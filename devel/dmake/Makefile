# New ports collection makefile for:	dmake
# Date created:		31 July 1995
# Whom:			nils@guru.ims.uni-stuttgart.de
#
# $FreeBSD$
#

PORTNAME=	dmake
PORTVERSION=	4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.internat.freebsd.org/pub/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-src-export.all-unknown-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another hyper make utility

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC=${CC}
MAKEFILE=	makefile
ALL_TARGET=	bsd43
MAN1=		dmake.1

post-extract:
.for f in limits.h string.h dirent.h
	@${RM} -f ${WRKSRC}/unix/bsd43/${f}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/unix/startup.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dmake ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dmake.tf ${PREFIX}/man/man1/dmake.1
	@${MKDIR} ${PREFIX}/share/dmake/startup
	${CP} -R ${WRKSRC}/startup/* ${PREFIX}/share/dmake/startup

.include <bsd.port.mk>
