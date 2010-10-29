# New ports collection makefile for:	tya
# Date created:		16 May 1999
# Whom:			jburkhol@home.com
#
# $FreeBSD$
#

PORTNAME=	tya
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/tya|}
DISTNAME=	tya18
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ``100% unofficial'' JIT-compiler for java

DEPRECATED=	looks like abandonware and does not compile wth gcc4.2
EXPIRATION_DATE=	2010-12-30

USE_JAVA=	yes
JAVA_VERSION=	1.3
JAVAOS=		native

WRKSRC=		${WRKDIR}/${DISTNAME:S/a1/a1./}

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jdk=${JAVA_HOME}

JAVALIBDIR=	${PREFIX}/lib/tya

post-patch:
	@${REINPLACE_CMD} -e "s|-malign|-falign|g" ${WRKSRC}/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/README

do-install:
	@${MKDIR} ${JAVALIBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/libtya.so ${JAVALIBDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${DOCSDIR}/README for usage instructions."
	@${ECHO_MSG} ""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
