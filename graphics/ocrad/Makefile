# New ports collection makefile for:	graphics/ocrad
# Date created:				12.11.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	ocrad
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	q@uni.de
COMMENT=	OCR program implemented as filter

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GCC=	3.2

CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		CXX=${CXX}

DOCS=		AUTHORS ChangeLog NEWS README TODO
INFO=		ocrad
MAN1=		ocrad.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ocrad ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} && cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/doc/ocrad.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/doc/ocrad.info ${PREFIX}/info
	@install-info ${PREFIX}/info/ocrad.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
