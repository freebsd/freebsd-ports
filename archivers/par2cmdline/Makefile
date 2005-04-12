# New ports collection makefile for:	par2cmdline
# Whom:					Chris Larsen <darth@vader.dk>
# Date created:				24 July 2003
#
# $FreeBSD$
#

PORTNAME=	par2cmdline
PORTVERSION=	0.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	parchive
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for using Parity v2 Archive files

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	README
PLIST_FILES=	bin/par2 bin/par2create bin/par2repair bin/par2verify

post-patch:
	@${REINPLACE_CMD} -e 's| -lstdc++||g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
