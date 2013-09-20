# Created by: jaharkes
# $FreeBSD$

PORTNAME=	rvm
PORTVERSION=	1.17
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A persistent VM library

LIB_DEPENDS=	lwp.2:${PORTSDIR}/devel/lwp

USES=		pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		rdsinit.1 rvmutl.1

NO_STAGE=	yes
post-extract:
.for file in Makefile.in
	@${REINPLACE_CMD} -e \
		's#(libdir)#{prefix}/libdata#g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
