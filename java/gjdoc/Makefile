# New ports collection makefile for:   gjdoc
# Date created:                8 March 2006
# Whom:                        Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gjdoc
PORTVERSION=	0.7.7
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://www.antlr.org/download/:antlr
MASTER_SITE_SUBDIR=	classpath
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${ANTLR}.jar:antlr
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A documentation generation framework; javadoc alternative

BUILD_DEPENDS=	gcj41:${PORTSDIR}/lang/gcc41 \
		gcp:${PORTSDIR}/sysutils/coreutils

ANTLRVER=	2.7.5
ANTLR=		antlr-${ANTLRVER}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-antlr-jar=${ANTLR}.jar
CONFIGURE_ENV=	PATH="${WRKDIR}/bin:${PATH}" LDFLAGS="${PTHREAD_LIBS}"
MAKE_ENV=	PATH="${WRKDIR}/bin:${PATH}"
SCRIPT_ENV=	PATH="${WRKDIR}/bin:${PATH}"
PLIST_SUB=	PORTVERSION=${PORTVERSION}

MAN1=		gjdoc.1
INFO=		gjdoc

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Broken dependency
.endif

post-extract:
	@${CP} ${DISTDIR}/${ANTLR}.jar ${WRKSRC}
	@${MKDIR} ${WRKDIR}/bin
	@${LN} -s ${LOCALBASE}/bin/gcj41 ${WRKDIR}/bin/gcj
	@${LN} -s ${LOCALBASE}/bin/gij41 ${WRKDIR}/bin/gij
	@${LN} -s ${LOCALBASE}/bin/fastjar41 ${WRKDIR}/bin/fastjar

.include <bsd.port.post.mk>
