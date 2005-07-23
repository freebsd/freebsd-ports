# New ports collection makefile for:	helium
# Date created:				28 January 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	helium
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.cs.uu.nl/helium/distr/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Functional programming compiler for a subset of Haskell

BROKEN=		Does not build
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

.if defined(WITH_HINT)
USE_JAVA=	1.4+
DISTFILES+=	${PORTNAME}-${PORTVERSION}-src.tar.gz \
		Hint-${PORTVERSION}.jar
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src.tar.gz
PLIST_SUB=	HINT=""
.else
PLIST_SUB=	HINT="@comment "
.endif

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
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
	@${INSTALL_DATA} ${DISTDIR}/Hint-${PORTVERSION}.jar ${PREFIX}/share/java/helium
	@${ECHO_CMD} "To use Hint type"
	@${ECHO_CMD}
	@${ECHO_CMD} "java -DLVMPATH=\$$LVMPATH -jar ${PREFIX}/share/java/helium/Hint-${PORTVERSION}.jar"
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
