# New ports collection makefile for:	aewan
# Date created:				07.05.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	aewan
PORTVERSION=	0.9.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based program for the creation and editing of ascii art

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		aecat.1 aewan.1
MAN5=		aewan.5
PLIST_FILES=	bin/aecat bin/aewan

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|OSTYPE == |OSTYPE = |g' ${WRKSRC}/configure

do-install:
.for i in aecat aewan
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.for i in aecat.1 aewan.1
	${INSTALL_DATA} ${WRKSRC}/man/man1/${i} ${MANPREFIX}/man/man1
.endfor
.for i in aewan.5
	${INSTALL_DATA} ${WRKSRC}/man/man5/${i} ${MAN5PREFIX}/man/man5
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
