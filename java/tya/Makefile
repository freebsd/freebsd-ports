# New ports collection makefile for:	tya
# Date created:		16 May 1999
# Whom:			jburkhol@home.com
#
# $FreeBSD$
#

PORTNAME=	tya
PORTVERSION=	1.8
CATEGORIES=	java
MASTER_SITES=	http://sax.sax.de/~adlibit/
DISTNAME=	tya18
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ``100% unofficial'' JIT-compiler for java

BUILD_DEPENDS=	${JAVADIR}/bin/java:${PORTSDIR}/java/jdk11

WRKSRC=		${WRKDIR}/${DISTNAME:S/a1/a1./}

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jdk=${JAVADIR}

JAVADIR?=	${LOCALBASE}/jdk1.1.8
JAVALIBDIR=	${PREFIX}/lib/tya

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
post-patch:
	@${REINPLACE_CMD} -e "s|-malign|-falign|g" ${WRKSRC}/Makefile.in
.endif

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

.include <bsd.port.post.mk>
