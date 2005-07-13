# New ports collection makefile for:    picprog
# Date created:         31 August 1999
# Whom:                 Johan Kerckaert <kirk@bricsnet.com>
#
# $FreeBSD$
#

PORTNAME=	picprog
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	erik@smluc.org
COMMENT=	Serial port pic16c84 programmer

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

MAKE_ENV=	CXX="${CXX}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/picprog
MAN1=		picprog.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CXX=.*||; s|^CXXFLAGS=.*||; s|^LDFLAGS=.*||' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picprog ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/picprog.1 ${MAN1PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in README *.png picprog.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
