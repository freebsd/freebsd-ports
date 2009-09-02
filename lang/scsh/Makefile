# New ports collection makefile for:    scsh
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#

PORTNAME=	scsh
PORTVERSION=	0.6.7
CATEGORIES=	lang scheme
MASTER_SITES=	SF \
		ftp://ftp.scsh.net/pub/scsh/0.6/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A Unix shell embedded into Scheme, with access to all Posix calls

CONFLICTS=	scheme48-[0-9]*

CONFIGURE_ENV+=	LDFLAGS="-Wl,-E"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		fails to install on ${ARCH}
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lib-dirs-list='("${PREFIX}/lib/scsh/0.6")'

USE_GMAKE=	yes
ALL_TARGET=	enough
MAN1=		scsh.1
STRIP=		#empty

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
