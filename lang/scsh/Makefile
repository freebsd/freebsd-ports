# New ports collection makefile for:    scsh
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#

PORTNAME=	scsh
PORTVERSION=	0.6.4
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp.scsh.net/pub/scsh/0.6/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Unix shell embedded into Scheme, with access to all Posix calls

CONFIGURE_ENV+=	LDFLAGS="-Wl,-E"

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} != "i386"
BROKEN=		"fails to install on ${MACHINE_ARCH}"
.endif

GNU_CONFIGURE=	yes

ALL_TARGET=	enough
MAN1=		scsh.1
STRIP=

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/scsh
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && \
	 ${INSTALL_DATA} README RELEASE COPYING ${PREFIX}/lib/scsh/doc)
	@${RM} -f ${PREFIX}/share/doc/scsh
	@${LN} -fs ${PREFIX}/lib/scsh/doc ${PREFIX}/share/doc/scsh
.else
	@${RM} -rf ${PREFIX}/lib/scsh/doc
.endif
	@(cd ${WRKSRC} && \
	 ${CP} -R emacs ${PREFIX}/lib/scsh/)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
