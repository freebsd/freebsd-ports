# New ports collection makefile for:	pine
# Version required:     3.96
# Date created:		19 Nov1997
# Whom:			Wu Ching-hong <woju@FreeBSD.ee.Ntu.edu.TW>
#
# $Id: Makefile,v 1.1.1.1 1997/12/01 19:47:20 vanilla Exp $
#

DISTNAME=       pine3.96
PKGNAME=        zh-pine-3.96
CATEGORIES=     chinese mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	woju@FreeBSD.ee.Ntu.edu.TW

MAN1= 		pine.1 pico.1 pilot.1

post-install:
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/pine
	cd ${WRKSRC} && \
		${INSTALL_DATA} doc/tech-notes.txt ${PREFIX}/share/doc/pine

.include <bsd.port.mk>
