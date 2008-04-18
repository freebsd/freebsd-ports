# New ports collection makefile for:	rvm
# Date created:				Thu Apr  6 21:30:52 EDT 2000
# Whom:					jaharkes
#
# $FreeBSD$
#

PORTNAME=	rvm
PORTVERSION=	1.15
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A persistent VM library

LIB_DEPENDS=	lwp.2:${PORTSDIR}/devel/lwp

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-extract:
.for file in pkgs/Makefile.in
	@${REINPLACE_CMD} -e \
		's#(libdir)#{prefix}/libdata#g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
