# ex:ts=8
# New ports collection makefile for:	muddleftpd
# Date created:			Apr 22, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	muddleftpd
PORTVERSION=	1.3.13.1
CATEGORIES=	ftp
MASTER_SITES=	http://gnu.rtin.bz/ftp/savannah/files/muddleftpd/ \
		http://sunsite.rediris.es/pub/gnu/savannah/files/muddleftpd/ \
		http://mirrors.ibiblio.org/pub/mirrors/gnu/ftp/savannah/files/muddleftpd/ \
		http://www.mirrormonster.com/gnuftp/savannah/files/muddleftpd/ \
		http://ftp.linux.cz/pub/gnu/savannah/files/muddleftpd/ \
		http://gnu.mirrors.tds.net/pub/gnu/savannah/files/muddleftpd/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A new ftp server that can perform a variety of ftp tasks

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-authsmb

MAN1=		ftpwho.1 muddleftpd.1 mudpasswd.1
INFO=		muddleftpd

post-patch:
	@${REINPLACE_CMD} -e 's|^NEWMALLOC|#NEWMALLOC|g' ${WRKSRC}/Makefile.defs
	@${REINPLACE_CMD} -e 's|"/etc|"${PREFIX}/etc|g' ${WRKSRC}/defaults.h.in
	@${REINPLACE_CMD} -e 's|#include <malloc.h>||g' ${WRKSRC}/src/ftpd.h

do-install:
.for file in ftpwho muddleftpd mudlogd mudpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/info/muddleftpd.info ${PREFIX}/info
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
