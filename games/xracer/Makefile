# New ports collection makefile for:	xracer
# Date created:				Nov 6th 1999
# Whom:					troll
#
# $FreeBSD$
#

PORTNAME=	xracer
PORTVERSION=	0.94
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_FREEBSD_ORG}
MASTER_SITE_SUBDIR=	distfiles
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-data${EXTRACT_SUFX}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Awesome WipeOut clone for OpenGL and X11!

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

USE_GL=		glut
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:14 autoconf:213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-esd

PORTDOCS=	AUTHORS README README.html

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} != i386 && ${ARCH} != "amd64"
BROKEN=		Does not build on ${ARCH}
.endif

post-extract:
	@${TOUCH} ${WRKSRC}/stamp-h.in
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} -e 's|machine/joystick.h|sys/joystick.h|g' \
			configure.in src/joystick/freebsd.c
	${CHMOD} -R a=r ${WRKDIR}/${PORTNAME}-data
	${CHMOD} -R +X ${WRKDIR}/${PORTNAME}-data
post-install:
	@${MKDIR} ${DATADIR}
	@${TAR} -C ${WRKDIR}/xracer-data -cf - . | \
		${TAR} -C ${DATADIR} --unlink -xf -
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
