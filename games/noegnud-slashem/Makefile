# New ports collection makefile for:	noegnud-slashem
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
		${MASTER_SITE_SOURCEFORGE:S/$/:slashem/}
MASTER_SITE_SUBDIR=	slashem/:slashem
PKGNAMESUFFIX=	-slashem
DISTFILES=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}:noegnud \
		se006e4f8.tar.gz:slashem
EXTRACT_ONLY=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}

MAINTAINER=	llwang@infor.org
COMMENT=	The noeGNUd UI for the SLASH'EM variant of Nethack

RUN_DEPENDS=	${LOCALBASE}/share/${NOEGNUDVERSION}/data/gui:${PORTSDIR}/games/noegnud-data

NOEGNUDVERSION=	${PORTNAME}-0.8.0
USE_BISON=	build
USE_GL=		yes
WANT_SDL=	yes
USE_SDL=	sdl image mixer
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/variants
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
ALL_TARGET=	se006e4f8
INSTALL_TARGET=	install_se006e4f8

.include <bsd.port.pre.mk>

pre-everything::
.if ${HAVE_SDL}
	@${ECHO_MSG} "This port depends on SDL with OpenGL support."
	@${ECHO_MSG} "If your SDL does not support OpenGL, hit ^C now and reinstall SDL"
	@${ECHO_MSG} "with OpenGL support turned on."
.endif

post-extract:
	@${CP} ${DISTDIR}/se006e4f8.tar.gz ${WRKSRC}/tarballs
	(cd ${WRKSRC} && ${MAKE} slashem-0.0.6E4F8)

post-patch:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-slashem-0.0.6E4F8)
	@(${PATCH} ${PATCH_ARGS} < ${FILESDIR}/noegnud-slashem.patch)

do-configure:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-slashem-0.0.6E4F8/Makefile)

.include <bsd.port.post.mk>
