# New ports collection makefile for:	EZWGL
# Date created:				4 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	EZWGL
PORTVERSION=	1.50
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTFILES=	${DISTNAME}-demo.tgz ${DISTNAME}-doc.tgz ${DISTNAME}-src.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.4:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.include "${FILESDIR}/manpages"

post-extract:
	find ${WRKSRC} -name CVS | xargs ${RM} -rf

post-install:
.for file in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/doc/man3/${file} ${PREFIX}/man/man3
.endfor
	@${MKDIR} ${PREFIX}/share/examples/EZ
	${TAR} -C ${WRKSRC}/examples --exclude 'Makefile.in' -cf - . | \
		${TAR} -C ${PREFIX}/share/examples/EZ --unlink -xf -
	${TAR} -C ${WRKSRC} --exclude 'Makefile.in' -cf - demos | \
		${TAR} -C ${PREFIX}/share/examples/EZ --unlink -xf -
	find ${PREFIX}/share/examples/EZ | xargs ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	find ${PREFIX}/share/examples/EZ -type f | xargs ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/EZ
	${TAR} -C ${WRKSRC}/doc --exclude 'misc' -cf - html ps | \
		${TAR} -C ${PREFIX}/share/doc/EZ --unlink -xf -
	find ${PREFIX}/share/doc/EZ | xargs ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	find ${PREFIX}/share/doc/EZ -type f | xargs ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.post.mk>
