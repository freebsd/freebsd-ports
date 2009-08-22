# New ports collection makefile for:	noegnud-littlehack
# Date created:				7 April 2004
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	noegnud
PORTVERSION=	0.8.3
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/noegnud/downloads/${PORTVERSION}/:noegnud	\
		SF/nethack/nethack/3.4.2:nethack
PKGNAMESUFFIX=	-littlehack
DISTFILES=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}:noegnud	\
		nethack-342.tgz:nethack
EXTRACT_ONLY=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}

MAINTAINER=	llwang@infor.org
COMMENT=	The noeGNUd UI for the the LittleHack variation of Nethack

RUN_DEPENDS=	${LOCALBASE}/share/${NOEGNUDVERSION}/data/gui:${PORTSDIR}/games/noegnud-data

NOEGNUDVERSION=	${PORTNAME}-0.8.0
USE_BISON=	build
USE_GL=		yes
WANT_SDL=	yes
USE_SDL=	sdl image mixer
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/variants
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
ALL_TARGET=	lh001
INSTALL_TARGET=	install_lh001

.include <bsd.port.pre.mk>

pre-everything::
.if ${HAVE_SDL}
	@${ECHO_MSG} "This port depends on SDL with OpenGL support."
	@${ECHO_MSG} "If your SDL does not support OpenGL, hit ^C now and reinstall SDL"
	@${ECHO_MSG} "with OpenGL support turned on."
.endif

post-extract:
	@${CP} ${DISTDIR}/nethack-342.tgz ${WRKSRC}/tarballs
	(cd ${WRKSRC} && ${MAKE} littlehack-0.0.1)

post-patch:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-littlehack-0.0.1)
	@(${PATCH} ${PATCH_ARGS} < ${FILESDIR}/noegnud-littlehack.patch)

do-configure:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-littlehack-0.0.1/Makefile)

.include <bsd.port.post.mk>
