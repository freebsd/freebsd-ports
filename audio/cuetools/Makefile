# New ports collection makefile for:	cuetools
# Date created:		30 December 2003
# Whom:			Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cuetools
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/cuetools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities for working with cue files and toc files

USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		cuebreakpoints.1 cueconvert.1 cueprint.1
PORTDOCS=	README
PLIST_FILES=	bin/cuebreakpoints bin/cueconvert bin/cueprint

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
