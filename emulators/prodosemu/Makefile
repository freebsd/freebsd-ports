# New ports collection makefile for:	prodosemu
# Version required:	0.1
# Date created:		18th February 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $FreeBSD$
#

DISTNAME=	prodosemu.v0.1
PKGNAME=	prodosemu-0.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.apple.asimov.net/pub/apple_II/emulators/prodosemu/ \
		ftp://apple2.caltech.edu/pub/apple2/emulators/

MAINTAINER=	ports@FreeBSD.org

NO_PACKAGE=	yes
RESTRICTED=	apple.rom copyright is owned by Apple and cannot be distributed.
WRKSRC=		${WRKDIR}/prodosemu-v0.1

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/*.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/prodosemu
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/prodosemu
.endif

.include <bsd.port.mk>
