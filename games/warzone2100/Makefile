# New ports collection makefile for:	warzone2100
# Date created:				21 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	warzone2100
PORTVERSION=	0.2.2
PORTREVISON=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		mad.2:${PORTSDIR}/audio/libmad \
		ogg.5:${PORTSDIR}/audio/libogg \
		openal.0:${PORTSDIR}/audio/openal \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		alut.0:${PORTSDIR}/audio/freealut

USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	net sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

SUB_FILES=	warzone

post-patch:
# Remove "-m32" flag
	@${REINPLACE_CMD} -e 's|-m32||' \
				${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
				${WRKSRC}/makerules/common.mk

# Fix SDL include statement
.for f in configure *.c *.h
	@${FIND} ${WRKSRC} -type f -name "${f}" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		's|\(#include.*\)SDL/\(SDL.*\)|\1\2| ; \
		s|-lopenal |&-lalut|g ; \
		s|"-lalut|"-lopenal -lalut|'
.endfor

do-install:
# Script
	@${INSTALL_SCRIPT} ${WRKDIR}/warzone ${PREFIX}/bin

# Program
	@${INSTALL_PROGRAM} ${WRKSRC}/src/warzone ${PREFIX}/libexec

# Data
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/data/* ${DATADIR}

# Documentation
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
# Fix permissions
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile (missing stdint.h)
.endif

.include <bsd.port.post.mk>
