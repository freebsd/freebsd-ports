# ex:ts=8
# New ports collection makefile for:	muddleftpd
# Date created:			Apr 22, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	muddleftpd
PORTVERSION=	1.3.12.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A new ftp server that can perform a variety of ftp tasks

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		ftpwho.1 muddleftpd.1 mudpasswd.1

post-patch:
	@${REINPLACE_CMD} -e 's|^NEWMALLOC|#NEWMALLOC|g' ${WRKSRC}/Makefile.defs
	@${REINPLACE_CMD} -e 's|"/etc|"${PREFIX}/etc|g' ${WRKSRC}/defaults.h
	@${REINPLACE_CMD} -e 's|#include <malloc.h>||g' ${WRKSRC}/src/ftpd.h

post-install:
	@install-info ${PREFIX}/info/muddleftpd.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
