# New ports collection makefile for:	rpc2
# Date created:				Wed Mar 22 19:06:45 EST 2000
# Whom:					jaharkes
#
# $FreeBSD$
#

PORTNAME=	rpc2
PORTVERSION=	2.10
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interprocess communication library

LIB_DEPENDS=	lwp.2:${PORTSDIR}/devel/lwp

USE_GMAKE=	yes
USE_PKGCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes

USE_LDCONFIG=	yes

post-extract:
	@${REINPLACE_CMD} -e \
		's#(libdir)#{prefix}/libdata#g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
