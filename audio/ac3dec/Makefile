# New ports collection makefile for:	ac3dev
# Date created:				23 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ac3dec
PORTVERSION=	0.6.1
CATEGORIES=	audio
MASTER_SITES=	http://dara.notbsd.org/~aholtzma/ac3/tarballs/

MAINTAINER=	3d@FreeBSD.org

GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386 alpha

post-patch:
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' \
	    < ${WRKSRC}/output.c > ${WRKSRC}/output.c.new
	@${MV} ${WRKSRC}/output.c.new ${WRKSRC}/output.c

pre-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ac3dec
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ac3dec/README
.endif

.include <bsd.port.mk>
