# New ports collection makefile for:	cgit
# Date created:				Oct 16 2008
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgit
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	devel www
MASTER_SITES= 	http://hjemli.net/git/cgit/snapshot/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	A fast webinterface for git

BUILD_DEPENDS=	${LOCALBASE}/bin/curl-config:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CGIT_SCRIPT_PATH=${WWWDIR} \
		CGIT_CONFIG=${PREFIX}/etc/cgitrc

SUB_FILES=	pkg-message

post-install:
	@${MKDIR} /var/cache/${PORTNAME}
	@${CHOWN} ${WWWOWN}:${WWWGRP} /var/cache/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc.5.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
