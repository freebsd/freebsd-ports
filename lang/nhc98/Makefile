# New ports collection makefile for:	nhc98
# Date created:				04 October 2001
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	nhc98
PORTVERSION=	1.14a
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/${PORTNAME}/
DISTNAME=	${PORTNAME}src-${PORTVERSION}
DIST_SUBDIR=	nhc98

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-1.14-Time

MAINTAINER=	obraun@FreeBSD.org

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

.if ${OSVERSION} >= 500000
CONFIGURE_ARGS+=	--buildwith=ghc
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/nhc98 +docs
.endif

MAN1=		harch.1 hmake.1 hp2graph.1 nhc98.1

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/Makefile.inc
.for file in Decl FillIn Process
	@${REINPLACE_CMD} -e '/^import PrelBase/d' \
		${WRKSRC}/src/greencard/${file}.lhs
.endfor

post-configure:
	@${ECHO} "LIBDIR=${PREFIX}/lib/nhc98" \
		>> ${WRKSRC}/targets/ix86-FreeBSD/config.cache

pre-install:
.if exists(${PREFIX}/bin/hmake) && !defined(OVERRIDE_HMAKE)
	@${ECHO} ""
	@${ECHO} "It seems that there is already a version of hmake installed on"
	@${ECHO} "this system. Since hmake is part of nhc98, please deinstall it,"
	@${ECHO} "or define OVERRIDE_HMAKE to override the installed version."
	@${ECHO} ""
	@${FALSE}
.endif

post-install:
	${SED} -e "s#/usr/doc/nhc98#${PREFIX}/share/doc/nhc98#" \
	       < ${WRKSRC}/man/nhc98.1 > ${WRKSRC}/man/nhc98.1.fix
	${INSTALL_MAN} ${WRKSRC}/man/nhc98.1.fix ${PREFIX}/man/man1/nhc98.1
	${RM} ${WRKSRC}/man/nhc98.1.fix
.if !defined(NOPORTDOCS)
.for ending in aux log
	${RM} ${PREFIX}/share/doc/nhc98/hat/tutorial1.${ending}
.endfor
.for ending in aux log out toc
	${RM} ${PREFIX}/share/doc/nhc98/hat/hatuser.${ending}
.endfor
.for directory in . bugs examples hat hmake implementation-notes libs
	${RM} -r ${PREFIX}/share/doc/nhc98/${directory}/CVS
.endfor
.endif

.include <bsd.port.post.mk>
