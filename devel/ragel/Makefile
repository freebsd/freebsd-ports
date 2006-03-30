# ex:ts=8
# Ports collection makefile for:	ragel
# Date created:			Mar 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ragel
PORTVERSION=	5.5
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.queensu.ca/home/thurston/ragel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ENV=	GPERF="${LOCALBASE}/bin/gperf"

MAN1=		ragel.1 rlcodegen.1
PLIST_FILES=	bin/ragel bin/rlcodegen

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(CFLAGS)|$$(CXXFLAGS)|g ; \
		 s|gperf -L|$$(GPERF) -L|g'

post-build:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		ragel.1 rlcodegen.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/ragel ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rlcodegen/rlcodegen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ragel.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/rlcodegen.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
