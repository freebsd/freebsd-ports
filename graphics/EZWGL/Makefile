# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	EZWGL
PORTVERSION=	1.50
PORTREVISION=	7
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTFILES=	${DISTNAME}-demo.tgz ${DISTNAME}-doc.tgz ${DISTNAME}-src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The EZ Widget and Graphics Library

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng15.so:${PORTSDIR}/graphics/png

USE_XORG=	x11 xext
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LIBS+=		-L${LOCALBASE}/lib
NOPRECIOUSMAKEVARS=	yes # Otherwise 'make readmes' is broken

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.include "${FILESDIR}/manpages"

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-extract:
	${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

post-install:
.for file in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/doc/man3/${file} ${PREFIX}/man/man3
.endfor
	@${MKDIR} ${PREFIX}/share/examples/EZ
	${TAR} -C ${WRKSRC}/examples --exclude 'Makefile.in' -cf - . | \
		${TAR} -C ${PREFIX}/share/examples/EZ --unlink -xf -
	${TAR} -C ${WRKSRC} --exclude 'Makefile.in' -cf - demos | \
		${TAR} -C ${PREFIX}/share/examples/EZ --unlink -xf -
	${FIND} ${PREFIX}/share/examples/EZ | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/share/examples/EZ -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/EZ
	${TAR} -C ${WRKSRC}/doc --exclude 'misc' -cf - html ps | \
		${TAR} -C ${PREFIX}/share/doc/EZ --unlink -xf -
	${FIND} ${PREFIX}/share/doc/EZ | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/share/doc/EZ -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.post.mk>
