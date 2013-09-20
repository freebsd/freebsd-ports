# Created by: jaharkes
# $FreeBSD$

PORTNAME=	lwp
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/lwp/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A userspace thread library

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-extract:
	@${REINPLACE_CMD} -e \
		's#(libdir)#{prefix}/libdata#g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
