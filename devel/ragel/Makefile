# ex:ts=8
# Ports collection makefile for:	ragel
# Date created:			Mar 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ragel
PORTVERSION=	3.6
CATEGORIES=	devel
MASTER_SITES=	http://www.elude.ca/ragel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	AWK="${AWK}"

MAN1=		ragel.1
PLIST_FILES=	bin/ragel

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(CFLAGS)|$$(CXXFLAGS)|g'

post-build:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ragel.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ragel.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
