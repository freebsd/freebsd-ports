# New ports collection makefile for:	lwp
# Date created:				Tue Mar 21 17:51:25 EST 2000
# Whom:					jaharkes
#
# $FreeBSD$
#

PORTNAME=	lwp
PORTVERSION=	2.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/lwp/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A userspace thread library

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
