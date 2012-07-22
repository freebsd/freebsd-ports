# New ports collection makefile for:	rvm
# Date created:				Thu Apr  6 21:30:52 EDT 2000
# Whom:					jaharkes
#
# $FreeBSD$
#

PORTNAME=	rvm
PORTVERSION=	1.17
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A persistent VM library

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	lwp.2:${PORTSDIR}/devel/lwp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		rdsinit.1 rvmutl.1

post-extract:
.for file in Makefile.in
	@${REINPLACE_CMD} -e \
		's#(libdir)#{prefix}/libdata#g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
