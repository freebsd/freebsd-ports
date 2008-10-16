# New ports collection makefile for:	cgit
# Date created:				Oct 16 2008
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgit
PORTVERSION=	0.8.1
CATEGORIES=	devel www
MASTER_SITES= 	http://hjemli.net/git/cgit/snapshot/:cgit \
		http://www.kernel.org/pub/software/scm/git/:git
DISTFILES=	cgit-${SHA1}${EXTRACT_SUFX}:cgit \
		git-${GIT_VERSION}.tar.bz2:git
SHA1=		140012d7a8e51df5a9f9c556696778b86ade4fc9
GIT_VERSION=	1.6.0.2

MAINTAINER=	flz@FreeBSD.org
COMMENT=	A fast webinterface for git

BUILD_DEPENDS=	${LOCALBASE}/bin/curl-config:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/${PORTNAME}
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

post-extract:
	@${RMDIR} ${WRKSRC}/git
	@${MV} ${WRKDIR}/git-${GIT_VERSION} ${WRKSRC}/git

post-install:
	@${MKDIR} /var/cache/${PORTNAME} ${DOCSDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} /var/cache/${PORTNAME}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc.5.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
