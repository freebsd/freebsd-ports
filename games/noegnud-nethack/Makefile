# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	noegnud
PORTVERSION=	0.8.3
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/noegnud/downloads/${PORTVERSION}/:noegnud	\
		SF/nethack/nethack/3.4.3:nethack
PKGNAMESUFFIX=	-nethack
DISTFILES=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}:noegnud	\
		nethack-343-src.tgz:nethack
EXTRACT_ONLY=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The noeGNUd UI for the vanilla Nethack

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	noegnud-data>0:games/noegnud-data

NOEGNUDVERSION=	${PORTNAME}-0.8.0
USES=		bison gmake tar:bzip2
USE_GL=		yes
USE_SDL=	sdl image mixer
WRKSRC=		${WRKDIR}/${DISTNAME}/variants
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
ALL_TARGET=	nh343
INSTALL_TARGET=	install_nh343
MAKE_JOBS_UNSAFE=	yes

pre-everything::
	@${ECHO_MSG} "This port depends on SDL with OpenGL support."
	@${ECHO_MSG} "If your SDL does not support OpenGL, hit ^C now and reinstall SDL"
	@${ECHO_MSG} "with OpenGL support turned on."

post-extract:
	@${CP} ${DISTDIR}/nethack-343-src.tgz ${WRKSRC}/tarballs
	(cd ${WRKSRC} && ${MAKE} nethack-3.4.3)

post-patch:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-nethack-3.4.3)
	@(${PATCH} ${PATCH_ARGS} < ${FILESDIR}/noegnud-nethack.patch)
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|make|${MAKE_CMD}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E -e 's,ch(grp|own),true,' \
		-e '/(^VARDIR|ln -s|sed)/! s,(GAME|SHELL|VAR)DIR),DESTDIR)$$(&,g' \
		-e '/ln -s/ s,SHELLDIR,DESTDIR)$$(&,2' \
		${WRKSRC}/${NOEGNUDVERSION}-nethack-3.4.3/sys/unix/Makefile.top

do-configure:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-nethack-3.4.3/Makefile)

.include <bsd.port.mk>
