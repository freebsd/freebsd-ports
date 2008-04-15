# New ports collection makefile for:	lwp
# Date created:				Tue Mar 21 17:51:25 EST 2000
# Whom:					jaharkes
#
# $FreeBSD$
#

PORTNAME=	lwp
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/lwp/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A userspace thread library

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

post-extract:
.for file in pkgs/Makefile.in
	@${REINPLACE_CMD} -e \
		's#(libdir)#{prefix}/libdata#g' \
		${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
