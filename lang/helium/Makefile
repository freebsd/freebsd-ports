# New ports collection makefile for:	helium
# Date created:				28 January 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	helium
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.cs.uu.nl/helium/distr/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Functional programming compiler for a subset of Haskell

.if defined(WITH_HINT)
USE_JAVA=	1.4+
DISTFILES+=	${PORTNAME}-${PORTVERSION}-src.tar.gz \
		Hint.jar
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src.tar.gz
PLIST_SUB=	HINT=""
.else
PLIST_SUB=	HINT="@comment "
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500035
BROKEN=	does not compile
.endif

BUILD_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_SIZE=	yes
USE_GMAKE=	yes

.if !defined(WITH_HINT)
pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Define WITH_HINT=yes to install Hint (needs Java >=1.4)."
	@${ECHO_CMD}
.endif

do-configure:
	@(cd ${WRKSRC}/lvm/src/  && ./configure)
	@(cd ${WRKSRC}/heliumNT/ && ./configure)

do-build:
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE} depend)
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE})

do-install:
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE} install)
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'
.if defined(WITH_HINT)
	@${MKDIR} ${PREFIX}/share/java/helium
	@${INSTALL_DATA} ${DISTDIR}/Hint.jar ${PREFIX}/share/java/helium
	@${ECHO_CMD} "To use Hint type"
	@${ECHO_CMD}
	@${ECHO_CMD} "java -DLVMPATH=\$$LVMPATH -jar ${PREFIX}/share/java/helium/Hint.jar"
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
