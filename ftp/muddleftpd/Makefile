# ex:ts=8
# New ports collection makefile for:	muddleftpd
# Date created:			Apr 22, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	muddleftpd
PORTVERSION=	1.3.11
CATEGORIES=	ftp
MASTER_SITES=	http://www.arach.net.au/~wildfire/muddleftpd/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		muddleftpd.1 ftpwho.1 mudpasswd.1

post-patch:
	@${REINPLACE_CMD} -e 's|^NEWMALLOC|#NEWMALLOC|g' ${WRKSRC}/Makefile.defs
	@${REINPLACE_CMD} -e 's|"/etc|"${PREFIX}/etc|g' ${WRKSRC}/defaults.h
	@${REINPLACE_CMD} -e 's|#include <malloc.h>||g' ${WRKSRC}/src/ftpd.h

pre-configure:
	@${CHMOD} -f u+x ${WRKSRC}/configure

post-install:
	install-info ${PREFIX}/info/muddleftpd.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/muddleftpd
	${INSTALL_DATA} ${WRKSRC}/examples/README ${PREFIX}/share/examples/muddleftpd
	${INSTALL_DATA} ${WRKSRC}/examples/*.conf ${PREFIX}/share/examples/muddleftpd
	@${MKDIR} ${PREFIX}/share/doc/muddleftpd
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${PREFIX}/share/doc/muddleftpd
.endif

.include <bsd.port.mk>
