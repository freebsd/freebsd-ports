# New ports collection makefile for:	fyre
# Date created:				2004 11 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fyre
PORTVERSION=	0.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.kerneled.org/files/FreeBSD-ports/ \
		http://navi.cx/releases/

MAINTAINER=	samy@kerneled.org
COMMENT=	Chaos map rendering system with GTK+-2 interface

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	libglade2
USE_GETOPT_LONG=yes

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
.if defined(WITH_OPTIMIZED_CFLAGS)
CPPFLAGS+=	-march=i686 -O3 -ffast-math \
		-fomit-frame-pointer -D__NO_INLINE__
.else
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_OPTIMIZED_CFLAGS to enable"
	@${ECHO_CMD} "compiler optimizations."
	@${ECHO_CMD} ""
.endif
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/data/*.glade \
		${PREFIX}/share/gnome/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
