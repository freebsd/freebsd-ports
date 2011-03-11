# New ports collection makefile for:	cgit
# Date created:				Oct 16 2008
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgit
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://hjemli.net/git/cgit/snapshot/:cgit \
		${MASTER_SITE_KERNEL_ORG:S/$/:git/g}
MASTER_SITE_SUBDIR=	software/scm/git/:git
DISTFILES=	cgit-${PORTVERSION}${EXTRACT_SUFX}:cgit \
		git-${GIT_VERSION}.tar.bz2:git
GIT_VERSION=	1.7.4

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A fast webinterface for git

BUILD_DEPENDS=	${LOCALBASE}/bin/curl-config:${PORTSDIR}/ftp/curl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CGIT_SCRIPT_PATH=${WWWDIR} \
		CGIT_CONFIG=${PREFIX}/etc/cgitrc \
		NEEDS_LIBICONV=yes

SUB_FILES=	pkg-message

post-extract:
	@${RMDIR} ${WRKSRC}/git
	@${MV} ${WRKDIR}/git-${GIT_VERSION} ${WRKSRC}/git

post-patch:
	@${REINPLACE_CMD} -e '/^CC =/d' ${WRKSRC}/git/Makefile
	@${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/' \
		-e 's,/usr,${PREFIX},g'  ${WRKSRC}/Makefile

post-install:
	@${MKDIR} /var/cache/${PORTNAME}
	@${CHOWN} ${WWWOWN}:${WWWGRP} /var/cache/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc.5.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
