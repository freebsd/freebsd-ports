# New ports collection makefile for:	noegnud-nethack
# Date created:				7 April 2004
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	noegnud
PORTVERSION=	0.8.3
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/noegnud/downloads/${PORTVERSION}/:noegnud	\
		${MASTER_SITE_SOURCEFORGE:S/$/:nethack/}
MASTER_SITE_SUBDIR=	nethack/:nethack
PKGNAMESUFFIX=	-nethack
DISTFILES=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}:noegnud	\
		nethack-343-src.tgz:nethack
EXTRACT_ONLY=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}

MAINTAINER=	llwang@infor.org
COMMENT=	The noeGNUd UI for the vanilla Nethack

RUN_DEPENDS=	${LOCALBASE}/share/${NOEGNUDVERSION}/data/gui:${PORTSDIR}/games/noegnud-data

NOEGNUDVERSION=	${PORTNAME}-0.8.0
USE_BISON=	yes
USE_GL=		yes
WANT_SDL=	yes
USE_SDL=	sdl image mixer
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/variants
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
ALL_TARGET=	nh343
INSTALL_TARGET=	install_nh343

.include <bsd.port.pre.mk>

pre-everything::
.if ${HAVE_SDL}
	@${ECHO_MSG} "This port depends on SDL with OpenGL support."
	@${ECHO_MSG} "If your SDL does not support OpenGL, hit ^C now and reinstall SDL"
	@${ECHO_MSG} "with OpenGL support turned on."
.endif

post-extract:
	@${CP} ${DISTDIR}/nethack-343-src.tgz ${WRKSRC}/tarballs
	(cd ${WRKSRC} && ${MAKE} nethack-3.4.3)

post-patch:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-nethack-3.4.3)
	@(${PATCH} ${PATCH_ARGS} < ${FILESDIR}/noegnud-nethack.patch)
.if ${OSVERSION} < 502103
	@${REINPLACE_CMD} -e 's/regex\.h/gnuregex\.h/'	\
		${WRKSRC}/nethack-3.4.3/src/sounds.c	\
		${PATCH_WRKSRC}/noegnud/noegnud_textcolour.c	\
		${PATCH_WRKSRC}/noegnud/noegnud_textcolour.h	\
		${PATCH_WRKSRC}/noegnud/noegnud_textcolouring.c
.endif

do-configure:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-nethack-3.4.3/Makefile)

.include <bsd.port.post.mk>
