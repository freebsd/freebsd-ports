# New ports collection makefile for:	Willows
# Date created:		5 June 1999
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	twin
PORTVERSION=	1999.12.30
CATEGORIES=	emulators devel
MASTER_SITES=	ftp://ftp.willows.com/pub/development/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		$(WRKDIR)/twin
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	depend world
CONFIGURE_ARGS=

# This hack is in order to avoid a build error with optimizations on,
# a real bugfix will surely come soon.
pre-patch:
	${CP} $(WRKSRC)/windows/if32.s $(WRKSRC)/windows/if32.S

pre-configure:
	${ECHO} "configure_args = ${CONFIGURE_ARGS}"
	${ECHO} "configure_env = ${CONFIGURE_ENV}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/twin
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${PREFIX}/share/doc/twin
	${GZIP_CMD} ${PREFIX}/share/doc/twin/*
.endif

.include <bsd.port.mk>
