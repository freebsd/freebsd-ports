# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	noegnud
PORTVERSION=	0.8.3
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/noegnud/downloads/${PORTVERSION}/:noegnud	\
		SF/slashem/slashem-source/0.0.6E4F8:slashem
PKGNAMESUFFIX=	-slashem
DISTFILES=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}:noegnud \
		se006e4f8.tar.gz:slashem
EXTRACT_ONLY=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The noeGNUd UI for the SLASH'EM variant of Nethack

BROKEN=		unfetchable

RUN_DEPENDS=	noegnud-data>0:games/noegnud-data

NOEGNUDVERSION=	${PORTNAME}-0.8.0
USES=		bison gmake tar:bzip2
USE_GL=		yes
USE_SDL=	sdl image mixer
WRKSRC=		${WRKDIR}/${DISTNAME}/variants
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
ALL_TARGET=	se006e4f8
INSTALL_TARGET=	install_se006e4f8
MAKE_JOBS_UNSAFE=	yes

pre-everything::
	@${ECHO_MSG} "This port depends on SDL with OpenGL support."
	@${ECHO_MSG} "If your SDL does not support OpenGL, hit ^C now and reinstall SDL"
	@${ECHO_MSG} "with OpenGL support turned on."

post-extract:
	@${CP} ${DISTDIR}/se006e4f8.tar.gz ${WRKSRC}/tarballs
	(cd ${WRKSRC} && ${MAKE} slashem-0.0.6E4F8)

post-patch:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-slashem-0.0.6E4F8)
	@(${PATCH} ${PATCH_ARGS} < ${FILESDIR}/noegnud-slashem.patch)
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|make|${MAKE_CMD}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E -e 's,ch(grp|own),true,' \
		-e '/(^FILE_AREA|^VARDIR|ln -s|sed)/! s,(GAME|SHELL|VAR)DIR),DESTDIR)$$(&,g' \
		-e '/sed/! s,FILE_AREA_(BONES|DOC|LEVL|SAVE|SHARE|UNSHARE|VAR)),DESTDIR)$$(&,g' \
		-e '/ln -s/ s,SHELLDIR,DESTDIR)$$(&,2' \
		${WRKSRC}/${NOEGNUDVERSION}-slashem-0.0.6E4F8/sys/unix/Makefile.top

do-configure:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-slashem-0.0.6E4F8/Makefile)

.include <bsd.port.mk>
