# New ports collection makefile for:	Schism Tracker
# Date created:				26 May 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	schism
DISTVERSION=	0.2a
CATEGORIES=	audio
MASTER_SITES=	http://rigelseven.com/schism/dl/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A module tracker editor/player resembling impulse tracker

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_SDL=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GCC=	3.4+

# Dies with bus error unless building debug version
CXXFLAGS=	-g
CFLAGS=		-g

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|getopt\.h|unistd\.h|' \
		${WRKSRC}/src/bin2h.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
