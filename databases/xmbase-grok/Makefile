# New ports collection makefile for:	xmbase-grok
# Date created:		Sat Aug 30 13:29:42 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	xmbase-grok
PORTVERSION=	1.4.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.fu-berlin.de/pub/unix/databases/xmbase-grok/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@FreeBSD.org

USE_MOTIF=	yes
USE_IMAKE=	yes

GLOK_DATADIR=	${PREFIX}/lib/X11/xmbase-grok

post-install:
	${TAR} -C ${WRKSRC} -cf - grokdir | \
		${TAR} -C ${GLOK_DATADIR} --unlink -xf -
	find ${GLOK_DATADIR} | xargs ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	find ${GLOK_DATADIR} -type f | xargs ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
