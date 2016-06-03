# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	noegnud
PORTVERSION=	0.8.3
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/noegnud/downloads/${PORTVERSION}/:noegnud	\
		SF/nethack/nethack/3.4.2:nethack
PKGNAMESUFFIX=	-littlehack
DISTFILES=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}:noegnud	\
		nethack-342.tgz:nethack
EXTRACT_ONLY=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The noeGNUd UI for the LittleHack variation of Nethack

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	noegnud-data>0:games/noegnud-data

NOEGNUDVERSION=	${PORTNAME}-0.8.0
USES=		bison tar:bzip2
USE_GL=		yes
USE_SDL=	sdl image mixer
WRKSRC=		${WRKDIR}/${DISTNAME}/variants
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
ALL_TARGET=	lh001
INSTALL_TARGET=	install_lh001
MAKE_JOBS_UNSAFE=	yes

pre-everything::
	@${ECHO_MSG} "This port depends on SDL with OpenGL support."
	@${ECHO_MSG} "If your SDL does not support OpenGL, hit ^C now and reinstall SDL"
	@${ECHO_MSG} "with OpenGL support turned on."

post-extract:
	@${CP} ${DISTDIR}/nethack-342.tgz ${WRKSRC}/tarballs
	(cd ${WRKSRC} && ${MAKE} littlehack-0.0.1)

post-patch:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-littlehack-0.0.1)
	@(${PATCH} ${PATCH_ARGS} < ${FILESDIR}/noegnud-littlehack.patch)
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E -e 's,ch(grp|own),true,' \
		-e '/(^VARDIR|ln -s|sed)/! s,(GAME|SHELL|VAR)DIR),DESTDIR)$$(&,g' \
		-e '/ln -s/ s,SHELLDIR,DESTDIR)$$(&,2' \
		${WRKSRC}/${NOEGNUDVERSION}-littlehack-0.0.1/sys/unix/Makefile.top
do-configure:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-littlehack-0.0.1/Makefile)

.include <bsd.port.mk>
