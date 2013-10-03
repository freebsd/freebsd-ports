# Created by: jaharkes
# $FreeBSD$

PORTNAME=	rpc2
PORTVERSION=	2.10
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interprocess communication library

LIB_DEPENDS=	liblwp.so:${PORTSDIR}/devel/lwp

USES=		gmake pathfix perl5 pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
